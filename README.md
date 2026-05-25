# What is this project

## An f1 styled time reaction test

# Parts used

1) ESP32 Wroom 32
2) ST7735 TFT
3) Tactile Button

# Wiring

ST7735 TFT:

LED -> GPIO 15
SCK -> GPIO 18
SDA -> GPIO 23
A0 -> GPIO 2
RESET -> GPIO 5
CS -> GPIO4
GND -> GND
VCC -> 3V3

Button

GND -> GND
OUTPUT -> D22

# How to use

1) Upload code to ESP 32
2) Press button when all lights go out
3) Time given is in milli second
4) Inorder to restart press button again
