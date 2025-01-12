#include <Adafruit_MCP4725.h>
#include <Adafruit_INA219.h>
#include <Arduino.h>

Adafruit_MCP4725 dac;
Adafruit_INA219 ina219;

#define DAC_ADDRESS 0x60
#define MAX_VOLTAGE 3.3 // Tensiunea maximă în volți
#define RESOLUTION 4095 // Rezoluția DAC-ului (12 biți)

float voltage = 0.0;      // Tensiunea curentă
float increase_step = 0.05; // Creștere tensiune (în volți)
float decrease_step = 0.03; // Scădere tensiune (în volți)
int delay_time = 200;       // Întârziere între schimbările de tensiune (ms)

TaskHandle_t dacTaskHandle = NULL;

void dacTask(void *pvParameters) {
    for (;;) {
        // Crește tensiunea
        voltage += increase_step;

        // Verifică limita superioară
        if (voltage > MAX_VOLTAGE) {
            voltage = 0; // Revine la 0 dacă depășește 3.3V
            Serial.println("Tensiunea a atins maximul și a fost resetată.");
        }

        // Setează tensiunea pe DAC
        dac.setVoltage((uint16_t)(voltage * RESOLUTION / MAX_VOLTAGE), false);
        Serial.print("Tensiune curentă (după creștere): ");
        Serial.print(voltage, 2); // Afișează cu două zecimale
        Serial.println(" V");

        vTaskDelay(pdMS_TO_TICKS(delay_time)); // Întârziere între iterații

        // Scade tensiunea
        voltage -= decrease_step;

        // Verifică limita inferioară
        if (voltage < 0) {
            voltage = 0; // Asigură-te că nu scade sub 0
            Serial.println("Tensiunea a atins minimul.");
        }

        // Setează tensiunea pe DAC
        dac.setVoltage((uint16_t)(voltage * RESOLUTION / MAX_VOLTAGE), false);
        Serial.print("Tensiune curentă (după scădere): ");
        Serial.print(voltage, 2); // Afișează cu două zecimale
        Serial.println(" V");

        vTaskDelay(pdMS_TO_TICKS(delay_time)); // Întârziere între iterații
    }
}

void setup() {
    Serial.begin(115200);

    if (!dac.begin(DAC_ADDRESS)) {
        Serial.println("Could not find a valid MCP4725 DAC!");
        while (1);
    }

    if (!ina219.begin()) {
        Serial.println("Could not find a valid INA219 sensor!");
        while (1);
    }

    // Creează sarcina FreeRTOS pentru DAC
    xTaskCreatePinnedToCore(
        dacTask,            // Funcția sarcinii
        "DAC Task",         // Numele sarcinii
        2048,               // Dimensiunea stivei (în bytes)
        NULL,               // Parametrii funcției (nefolosiți aici)
        1,                  // Prioritatea sarcinii
        &dacTaskHandle,     // Handle-ul sarcinii
        0                   // Rulează pe Core 0
    );
}

void loop() {
    // Bucla principală rămâne liberă pentru alte funcționalități
}
