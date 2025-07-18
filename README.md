# EMG Prosthetic Hand

A bioelectronic prosthetic hand controlled by real-time EMG signals. This project combines biomedical signal processing, analog circuitry, and embedded programming to enable intuitive motor-driven actuation for hand movement.

## 🛠️ Project Overview

**Duration:** Jan 2025 – Mar 2025  
This system interprets EMG signals from muscle activity to control servo motors on a 3D-printed prosthetic hand, allowing for natural, real-time movement. The project integrates hardware design, signal conditioning, and embedded software.

## 🔧 Features

- 3D-printed prosthetic hand with 5 servo motor joints
- EMG signal capture and amplification using:
  - DC offset correction
  - **LM741** operational amplifiers
  - **AD622** instrumentation amplifier
- Real-time analog signal filtering and gain tuning
- Arduino-based EMG signal interpretation and motor control

## ⚙️ Hardware & Tools

- **Arduino Mega 2560**
- **EMG electrodes**
- **AD622**, **LM741** op-amps
- **Servo motors** (SG90 or MG996R)
- **3D-printed hand** (PLA material)
- Breadboard & resistors/capacitors for signal filtering

## 🧠 How It Works

1. EMG signals are collected using surface electrodes.
2. Signals are passed through analog processing circuits for filtering and amplification.
3. Arduino reads processed EMG waveforms, identifies muscle contractions, and maps them to motor actuation patterns.
4. Servo motors respond in real time to open or close the prosthetic hand.

## 🧪 Results

- Achieved responsive, muscle-controlled hand movements with minimal delay.
- Real-time filtering significantly improved control accuracy and reduced false activations.

## 🧠 Code Files

- **`test_motor.ino`** – Simple motor test script that alternates servo position every 5 seconds.
- **`Test_EMG_Signal.ino`** – Reads analog EMG input, converts it to voltage, and outputs it via serial monitor for signal analysis.
- **`EMG_hand_control.ino`** – Core logic: interprets EMG signals and controls servo movement based on threshold detection and signal count logic. Includes timeout handling for inactivity and resets.

## 📃 License

Licensed under the [Apache 2.0 License](./LICENSE).
