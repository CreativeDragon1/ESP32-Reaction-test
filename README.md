# 🏎️ F1 Reaction Light Tester

An ESP32-powered reaction time tester inspired by the Formula 1 start light sequence.

> Demo: [Watch on YouTube Shorts](https://youtube.com/shorts/xIvpsd0aPk8?feature=share)

<img width="238" height="267" alt="image" src="https://github.com/user-attachments/assets/62a84219-edcf-4ae8-b3e4-30f90fdf7a8b" />
<img width="198" height="162" alt="image" src="https://github.com/user-attachments/assets/70b5f502-1bbc-4dcc-a971-af0a62f5496a" />

---

## Features

- Authentic F1-style 5-light countdown sequence
- Millisecond-accurate reaction timing
- False start detection (press too early = penalty screen)
- Compact build — fits on a breadboard or small enclosure
- One-button operation: test → result → restart

---

## Hardware Required

| Component | Qty |
|---|---|
| ESP32 WROOM-32 Dev Board | 1 |
| ST7735 1.8" TFT Display | 1 |
| Tactile Push Button | 1 |
| Jumper Wires | — |
| Breadboard or custom PCB | 1 |

See [`BOM.csv`](./BOM.csv) for purchase links.

---

## Wiring

### ST7735 TFT Display

| TFT Pin | ESP32 GPIO |
|---|---|
| VCC | 3.3V |
| GND | GND |
| CS | GPIO 4 |
| RESET | GPIO 5 |
| A0 (DC) | GPIO 2 |
| SDA (MOSI) | GPIO 23 |
| SCK | GPIO 18 |
| LED (BL) | GPIO 15 |

### Button

| Button Pin | ESP32 |
|---|---|
| One leg | GPIO 22 |
| Other leg | GND |

> GPIO 22 uses the internal pull-up resistor — no external resistor needed.

---

## Software Setup

### Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/software) or PlatformIO
- ESP32 board package installed ([guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html))
- Libraries (install via Library Manager):
  - `Adafruit ST7735` by Adafruit
  - `Adafruit GFX Library` by Adafruit

### Upload

1. Clone or download this repo
2. Open `esp32-code/esp32_reaction_test/esp32_reaction_test.ino` in Arduino IDE
3. Select board: **ESP32 Dev Module**
4. Select the correct COM port
5. Click **Upload**

---

## How to Use

1. Power on the ESP32 — the display will show a ready screen
2. Watch the five red lights illuminate one by one
3. When **all lights go out**, press the button as fast as possible
4. Your reaction time is displayed in **milliseconds**
5. Press the button again to **restart**

> **False start:** If you press before the lights go out, a penalty screen is shown. Press again to retry.

---

## Project Structure

```
ESP32-Reaction-test/
├── esp32-code/
│   └── esp32_reaction_test/
│       └── esp32_reaction_test.ino   # Main ESP32 Arduino sketch
├── README.md
└── BOM.csv
```

The ESP32 firmware is now isolated under `esp32-code/` so hardware code stays cleanly separated from docs and supporting files.

---

## License

MIT License — free to use, modify, and build on.
