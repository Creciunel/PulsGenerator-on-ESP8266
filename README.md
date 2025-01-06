# PulsGenerator-ESP32

## Description
PulsGenerator-ESP32 is a signal generator capable of producing various signal forms such as square, triangle, sawtooth, etc., using the DAC of the ESP32. The code is written in C using the Zephyr framework.

## Use Cases
- Generating signals for potentiostats
- Generating signals for oscilloscopes

![Potentiostat](IMG/Electrode%20schematic.png)

## Components Used
- **TDA2050A**: In perspective to use TDA7294, what is a 12-32V 85W Audio Power Amplifier. A monolithic integrated circuit designed for audio amplification, capable of delivering up to **35 W** true RMS power into a 4-ohm load. It features low distortion and includes protection mechanisms like short-circuit protection and thermal shutdown, making it suitable for high-fidelity audio applications.

- **INA219**: A high-side current shunt monitor with an I2C interface. It measures both current and voltage, providing power calculations for various applications, especially in battery management systems and energy monitoring.

- **MCP4725**: A 12-bit digital-to-analog converter (DAC) that communicates via I2C. It allows for precise voltage output control, making it ideal for generating analog signals from digital sources.

- **Resistors (10W)**: High-power resistors rated at 10 watts are used to handle significant power levels without overheating. These resistors are essential for managing current flow and ensuring stable operation within the circuit.

## Future Goals
The project aims to expand existing functionalities by adding the following features:
- **Complex Signal Generation**: Implementation of more advanced and customizable waveform shapes.
- **Graphical User Interface**: Creation of a GUI for controlling and visualizing generated signals.
- **Integration with Other Platforms**: Enabling the generator to connect with various hardware platforms for diverse applications.

## Software Testing
This project includes unit tests to ensure the correctness of functionalities. The tests are written using the Zephyr framework and can be easily run in the development environment.

## CI/CD
This project utilizes GitHub Actions for CI/CD implementation. This ensures that all changes are automatically tested before being merged into the main branch. The GitHub Actions configuration includes automated code checks and running unit tests.

## License
This project is licensed under the [MIT License](LICENSE).
