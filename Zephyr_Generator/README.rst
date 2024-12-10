.. zephyr:code-sample:: zephyr_generator
   :name: Zephyr Generator

   Generate various signal forms using the DAC of ESP32.

Overview
********

PulsGenerator-ESP32 is a signal generator capable of producing various signal forms such as square, triangle, sawtooth, etc., using the DAC of the ESP32.

Project Structure
*****************

The project directory structure is as follows:

Zephyr_Generator/
├── CMakeLists.txt
├── README.rst
├── esp32.overlay
├── prj.conf
└── src

- **CMakeLists.txt**: The main build configuration file.
- **README.rst**: This documentation file.
- **esp32.overlay**: Overlay file for board-specific configurations.
- **prj.conf**: Project configuration file for Zephyr settings.
- **src/**: Directory containing the source code for the application.

Building and Running
********************

To build and flash the application, run the following script from the project root directory:


./build.sh

This script will handle the building and flashing process automatically. Ensure that you have the necessary tools and dependencies installed as per the Zephyr documentation.

Sample Output
=============

Once the application is successfully flashed to the ESP32, it will generate signals as specified in the code.

Exit QEMU by pressing :kbd:`CTRL+A` :kbd:`x`.
