# Waste-segregation-using-robotic-arm

[![Language](https://img.shields.io/badge/Language-C%2B%2B-yellow.svg?style=for-the-badge)](https://en.wikipedia.org/wiki/Programming_language)
[![Language](https://img.shields.io/badge/Language-Python-blue.svg?style=for-the-badge)](https://www.python.org/)

This project automates the process of waste segregation using a robotic arm system. It employs computer vision techniques to identify waste types and instructs a robotic arm to pick and place them into appropriate bins, creating an integrated and intelligent sorting system.

---

## 📑 Table of Contents

- [Features](#features)
- [Technologies Used](#technologies-used)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

---

## 🚀 Features

- **Vision-Based Waste Identification**: Uses a trained object detection model (`best.pt`) to recognize different waste materials.
- **Robotic Arm Control**: Interfaces with a physical robotic arm to perform pick-and-place operations.
- **Integrated Workflow**: Seamless combination of video input, classification logic, and motor control.
- **Embedded Compatibility**: Can potentially run on platforms like Raspberry Pi (suggested by `rpif.py`).

---

## 🧰 Technologies Used

### Languages
- C++
- Python

### Python Libraries
Includes (but not limited to):
- `opencv-python`
- `numpy`
- `matplotlib`
- `gTTS`
- `certifi`, `charset-normalizer`, `contourpy`, `cycler`
- `fonttools`, `filelock`, `fsspec`, `Jinja2`, `MarkupSafe`
- `networkx`, `packaging`, `mpmath`, and more as listed in `requirements.txt`

---

## 🛠️ Installation

Follow these steps to install and run the system locally:

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/waste-segregation-using-robotic-arm.git
cd waste-segregation-using-robotic-arm
```

### 2. Install Python Dependencies

It’s recommended to use a virtual environment.

```bash
# Optional virtual environment
# python -m venv venv
# source venv/bin/activate     # For Linux/macOS
# venv\Scripts\activate        # For Windows

pip install -r requirements.txt
```

### 3. Build C++ Components

Navigate to the `RoboticArm` folder (if applicable) and compile using your preferred toolchain:

```bash
cd RoboticArm
# Example (adjust per platform):
# make
# OR
# cmake .
# make
```

### 4. Model Setup

Ensure the `best.pt` model file is placed in the project root directory. This file contains the trained weights for waste classification.

---

## ▶️ Usage

To begin the waste segregation process:

1. **Prepare Hardware**: Set up the robotic arm and camera module.
2. **Run the Main Script**:

```bash
python rpif.py
```

3. **Optional Arguments**:
```bash
# Use a connected webcam
python rpif.py --source 0

# Use a test video file
python rpif.py --source test.mp4
```

> Refer to the internal code of `rpif.py` to understand accepted arguments and expected formats.

---

## 🤝 Contributing

Contributions are welcome!

1. Fork the repository  
2. Create a new feature branch  
   ```bash
   git checkout -b feature/AmazingFeature
   ```
3. Commit your changes  
   ```bash
   git commit -m "Add AmazingFeature"
   ```
4. Push to your branch  
   ```bash
   git push origin feature/AmazingFeature
   ```
5. Open a Pull Request

---
