# feature-detection
Feature detection in an RGB image with OpenCV

This C++ project demonstrates feature detection in an RGB image using the OpenCV library. The project includes implementations for line detection (using Canny or Hough algorithms) and corner detection (using the Harris algorithm).

## Requirements

- C++ compiler
- OpenCV library (version 4.0 or later)

## How to Run

1. Clone the repository:

```bash
git clone https://github.com/emrekarapaca/feature-detection.git
cd feature-detection

g++ -o feature_detection main.cpp CommonProcesses.cpp LineDetection.cpp CornerDetection.cpp `pkg-config --cflags --libs opencv`

./feature_detection
![Ekran görüntüsü 2024-01-19 162656](https://github.com/emrekarapaca/feature-detection/assets/62401859/fc85b9fb-7e71-4229-87a5-354ae6dcc0e1)
