#include <LiquidCrystal_I2C.h>
#include <stdint.h>
#include <GyverEncoder.h>

#include "led-controller.h"
#include "brightness-view.h"
#include "color-view.h"
#include "mode-view.h"
#include "abstract-model.h"
#include "brightness-model.h"
#include "color-model.h"
#include "mode-model.h"
#include "vector.h"

#define LED_COUNT 94
#define LED_PIN 13

#define ENCODER_S1_PIN 6
#define ENCODER_S2_PIN 7
#define ENCODER_KEY_PIN 8

#define INITIAL_BRIGHTNESS 32
#define INITIAL_COLOR "warm"
#define INITIAL_MODE "light"
#define MODELS_COUNT 3

LiquidCrystal_I2C *lcd = new LiquidCrystal_I2C(0x27, 16, 2);

BrightnessModel *brightnessModel = new BrightnessModel();
ColorModel *colorModel = new ColorModel();
ModeModel *modeModel = new ModeModel();

BrightnessView *brightnessView = new BrightnessView(lcd);
ColorView *colorView = new ColorView(lcd);
ModeView *modeView = new ModeView(lcd);

AbstractModel *models[MODELS_COUNT] = {
  brightnessModel,
  colorModel,
  modeModel
};
uint8_t currentModel = 0;

LedController *ledController = new LedController(LED_PIN, LED_COUNT);
Encoder *encoder = new Encoder(ENCODER_S1_PIN, ENCODER_S2_PIN, ENCODER_KEY_PIN);

bool isBacklightTurnOn = false;

void nextModel() {
  if (currentModel == MODELS_COUNT - 1) {
    currentModel = 0;
  } else {
    currentModel++;
  }
}

void toggleBacklight() {
  isBacklightTurnOn = !isBacklightTurnOn;

  if (isBacklightTurnOn) {
    lcd->backlight();
  } else {
    lcd->noBacklight();
  }
}

void onBrightnessModelLeft() {
  brightnessModel->setBrightness(ledController->getBrightness() - BRIGHTNESS_STEP);
}

void onBrightnessModelRight() {
  uint8_t brightness = ledController->getBrightness();
  // Чтобы не было переполнения, т.к. uint8_t в диапазоне 0..255
  brightnessModel->setBrightness(brightness >= 256 - BRIGHTNESS_STEP ? 255 : brightness + BRIGHTNESS_STEP);
}

void onBrightnessModelChange() {
  brightnessView->showBrightnessLevel(brightnessModel->getBrightness());
  ledController->setBrightness(brightnessModel->getBrightness());
  ledController->show();
}

void onColorModelLeft() {
  colorModel->setColor(colorModel->getPrevColor(colorModel->getColorName()));
}

void onColorModelRight() {
  colorModel->setColor(colorModel->getNextColor(colorModel->getColorName()));
}

void onColorModelChange() {
  colorView->showColor(colorModel->getColorName());
  ledController->setColor(colorModel->getColorValue());
  ledController->show();
}

void onModeModelLeft() {
  modeModel->setMode(modeModel->getPrevMode());
}

void onModeModelRight() {
  modeModel->setMode(modeModel->getNextMode());
}

void onModeModelChange() {
  modeView->showMode(modeModel->getMode());
}

void setup() {
  Serial.begin(9600);

  lcd->init();
  lcd->backlight();

  ledController->begin();
  ledController->show();
  
  encoder->setType(TYPE2);
  encoder->setTickMode(AUTO);
  encoder->setFastTimeout(40);

  brightnessModel->on("left", onBrightnessModelLeft);
  brightnessModel->on("right", onBrightnessModelRight);
  brightnessModel->on("change", onBrightnessModelChange);

  colorModel->on("left", onColorModelLeft);
  colorModel->on("right", onColorModelRight);
  colorModel->on("change", onColorModelChange);

  modeModel->on("left", onModeModelLeft);
  modeModel->on("right", onModeModelRight);
  modeModel->on("change", onModeModelChange);

  modeModel->setMode(INITIAL_MODE);
  colorModel->setColor(INITIAL_COLOR);
  brightnessModel->setBrightness(INITIAL_BRIGHTNESS);
}

void loop() {
  if (encoder->isRight()) {
    models[currentModel]->emit("left");

  }
  if (encoder->isLeft()) {
    models[currentModel]->emit("right");
  }

  if (encoder->isClick()) {
    nextModel();
    models[currentModel]->emit("change");
  }

  if (encoder->isHolded()) {
    toggleBacklight();
  }
}
