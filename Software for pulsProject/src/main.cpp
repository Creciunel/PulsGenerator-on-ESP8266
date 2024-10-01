#include <Arduino.h>
#include <GyverMAX6675.h>

// Definirea pinilor pentru MAX6675
#define CLK_PIN 14  // Pinul pentru CLK
#define DATA_PIN 12 // Pinul pentru DATA
#define CS_PIN 15   // Pinul pentru CS

// Crearea instanței pentru senzorul MAX6675
GyverMAX6675<CLK_PIN, DATA_PIN, CS_PIN> sens;

void setup() {
    Serial.begin(115200); // Inițializarea comunicației seriale
    delay(1000); // Așteaptă 1 secundă pentru a permite conectarea serialului

    Serial.println("Testare termocuplu MAX6675...");
}

void loop() {
    // Citirea temperaturii
    if (sens.readTemp()) { // Verifică dacă citirea a avut succes
        float temperature = sens.getTemp(); // Obține temperatura
        Serial.print("Temperatura: ");
        Serial.print(temperature);
        Serial.println(" °C"); // Afișează temperatura în grade Celsius
    } else {
        Serial.println("Eroare la citirea temperaturii!");
    }

    delay(1000); // Așteaptă 1 secundă înainte de următoarea citire
}