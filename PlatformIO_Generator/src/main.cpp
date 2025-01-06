#include "main.hpp"

void setup()
{
    Serial.begin(115200);
    // Activează DAC Channel 1 (GPIO25)
    // dac_output_enable(DAC_CHANNEL_1);
    dac.begin(DAC_ADDRESS);
}

void loop()
{

    uint32_t counter;
    // Run through the full 12-bit scale for a triangle wave
    for (counter = 0; counter < 4095; counter++)
    {
        dac.setVoltage(counter, false);
    }
    for (counter = 4095; counter > 0; counter--)
    {
        dac.setVoltage(counter, false);
    }

    // static float voltage = 0.0;
    // static bool firstIteration = true; // Flag pentru prima iterație

    // if (firstIteration) {
    //     // Crește cu 50 mV doar la prima iterație
    //     voltage += 0.05;
    //     Serial.println("Prima iterație: Creștere cu 50 mV");
    //     firstIteration = false; // Schimbă flag-ul
    // } else {
    //     // Crește cu 60 mV
    //     voltage += 0.09;
    //     Serial.println("Creștere cu 60 mV");
    // }

    // // Asigură-te că tensiunea nu depășește 3.3V
    // if (voltage > 3.3) {
    //     voltage = 0;
    //     Serial.println("Tensiunea a atins maximul de 3.3V");
    // }

    // // Setează tensiunea DAC-ului
    // dac_output_voltage(DAC_CHANNEL_1, (uint8_t)(voltage * 255 / 3.3));
    // Serial.print("Tensiune curentă: ");
    // Serial.print(voltage, 2); // Afișează cu două zecimale
    // Serial.println(" V");
    // delay(10); // Așteaptă 100 ms

    // // Scade cu 30 mV
    // voltage -= 0.03;

    // // Asigură-te că tensiunea nu devine mai mică de 0V
    // if (voltage < 0) {
    //     voltage = 0;
    //     Serial.println("Tensiunea a atins minimul de 0V");
    // }

    // // Setează tensiunea DAC-ului
    // dac_output_voltage(DAC_CHANNEL_1, (uint8_t)(voltage * 255 / 3.3));
    // Serial.print("Tensiune curentă după scădere: ");
    // Serial.print(voltage, 2); // Afișează cu două zecimale
    // Serial.println(" V");
    // delay(20); // Așteaptă 200 ms
}