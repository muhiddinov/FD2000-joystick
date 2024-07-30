#ifndef MAIN_H
#define MAIN_H

#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

const char* bt_name = "FD2000-BT";

void digitalSignalTerminal (uint8_t pina, uint8_t pinb, uint8_t number, bool end);
void analogSignalTerminal (uint8_t pin, char number, bool end);

#define SW3_PIN_A   26
#define SW3_PIN_B   27

#define SW2_PIN_A   33
#define SW2_PIN_B   25

#define SW1_PIN_A   35
#define SW1_PIN_B   32

#define SW4_PIN_A   19
#define SW4_PIN_B   23

#define SW6_PIN_A   16
#define SW6_PIN_B   17

#define SW5_PIN_A   5
#define SW5_PIN_B   18

#define JS1_PIN_X   36
#define JS1_PIN_Y   39



#endif // !MAIN_H

