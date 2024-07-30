#include <Arduino.h>
#include <main.h>

#define DEBUG 1 // Serial monitor uchun 1

void setup() {
  #ifdef DEBUG
  Serial.begin(115200);
  #endif // DEBUG

  SerialBT.begin(bt_name);

  pinMode(SW1_PIN_A, INPUT_PULLUP);
  pinMode(SW1_PIN_B, INPUT_PULLUP);
  
  pinMode(SW2_PIN_A, INPUT_PULLUP);
  pinMode(SW2_PIN_B, INPUT_PULLUP);
  
  pinMode(SW3_PIN_A, INPUT_PULLUP);
  pinMode(SW3_PIN_B, INPUT_PULLUP);
  
  pinMode(SW4_PIN_A, INPUT_PULLUP);
  pinMode(SW4_PIN_B, INPUT_PULLUP);
  
  pinMode(SW5_PIN_A, INPUT_PULLUP);
  pinMode(SW5_PIN_B, INPUT_PULLUP);
  
  pinMode(SW6_PIN_A, INPUT_PULLUP);
  pinMode(SW6_PIN_B, INPUT_PULLUP);

  pinMode(JS1_PIN_X, INPUT);
  pinMode(JS1_PIN_Y, INPUT);
}

void loop() {
  digitalSignalTerminal(SW1_PIN_A, SW1_PIN_B, 1, false);
  digitalSignalTerminal(SW2_PIN_A, SW2_PIN_B, 2, false);
  digitalSignalTerminal(SW3_PIN_A, SW3_PIN_B, 3, false);
  digitalSignalTerminal(SW4_PIN_A, SW4_PIN_B, 4, false);
  digitalSignalTerminal(SW5_PIN_A, SW5_PIN_B, 5, false);
  digitalSignalTerminal(SW6_PIN_A, SW6_PIN_B, 6, false);
  analogSignalTerminal(JS1_PIN_X, 'X', false);
  analogSignalTerminal(JS1_PIN_Y, 'Y', true);
  delay(100);
}

void digitalSignalTerminal (uint8_t pina, uint8_t pinb, uint8_t number, bool end) {
  int8_t stat = -1;
  bool a = digitalRead(pina);
  bool b = digitalRead(pinb);
  if (a && b) {
    stat = 0;
  } else if (!a && b) {
    stat = 1;
  } else if (a && !b) {
    stat = 2;
  }
  SerialBT.print(String("SW") + String(number) + ":" + String(stat));
  if (end) SerialBT.println();
  else SerialBT.print("#");

  #ifdef DEBUG
  Serial.print(String("SW") + String(number) + ":" + String(stat));
  if (end) Serial.println();
  else Serial.print("#");
  #endif // DEBUG
}

void analogSignalTerminal (uint8_t pin, char number, bool end) {
  int8_t stat = -1;
  uint16_t val = analogRead(pin);
  if (val > 4000) stat = 1;
  else if (val < 100) stat = 2;
  else stat = 0;
  SerialBT.print(String("JS") + String(number) + ":" + String(stat));
  if (end) SerialBT.println();
  else SerialBT.print("#");
  #ifdef DEBUG
  Serial.print(String("JS") + String(number) + ":" + String(stat));
  if (end) Serial.println();
  else Serial.print("#");
  #endif // DEBUG
}