#include <SoftwareSerial.h>
#include "EBYTE22.h"

#define PIN_TX 9 //LV1-D11
#define PIN_RX 8 //LV2-D10
#define PIN_M0 4 //LV3-D13
#define PIN_M1 5 //LV4-D12
#define PIN_AX 6 //D14 

SoftwareSerial E22Serial(PIN_TX, PIN_RX, false); // 
EBYTE22 E22(&E22Serial, PIN_M0, PIN_M1, PIN_AX); // 

void setup() {
  Serial.begin(9600);     // USB 
  E22Serial.begin(9600);  // LoRa 

  E22.init();            
}

void loop() {
  if (E22.available()) {
    String received = E22Serial.readString(); 
    Serial.println(received);                 
  }
}
