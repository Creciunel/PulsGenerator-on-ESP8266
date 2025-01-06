#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <driver/dac.h>
#include <Arduino.h>

Adafruit_MCP4725 dac;

#define DAC_ADDRESS 0x62