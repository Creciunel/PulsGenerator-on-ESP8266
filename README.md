# PulsGenerator-ESP32

## Description
PulsGenerator-ESP32 is a signal generator capable of producing various signal forms such as square, triangle, sawtooth, etc., using the DAC of the ESP32. The code is written in C using the Zephyr framework.

## Use Cases
- Generating signals for potentiostats
- Generating signals for oscilloscopes

![Potentiostat](IMG/Electrode%20schematic.png)

## Future Goals
The project aims to expand existing functionalities by adding the following features:
- **Complex Signal Generation**: Implementation of more advanced and customizable waveform shapes.
- **Graphical User Interface**: Creation of a GUI for controlling and visualizing generated signals.
- **Integration with Other Platforms**: Enabling the generator to connect with various hardware platforms for diverse applications.

## Software Testing
This project includes unit tests to ensure the correctness of functionalities. The tests are written using the Zephyr framework and can be easily run in the development environment.

## CI/CD
This project utilizes GitHub Actions for CI/CD implementation. This ensures that all changes are automatically tested before being merged into the main branch. The GitHub Actions configuration includes automated code checks and running unit tests.

<h2>License</h2>
<p>This project is licensed under the <a href="LICENSE">MIT License</a>.</p>
