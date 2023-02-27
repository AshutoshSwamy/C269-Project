#include <MD_MAX72xx.h>
#include <MD_Parola.h>
#include <SPI.h>

const byte clock_pin = 13;
const byte data_pin = 11;
const byte chip_select_pin = 10;
const byte max_devices = 4;

String data = "";

MD_Parola matrix = MD_Parola(MD_MAX72XX::PAROLA_HW, chip_select_pin, max_devices);

void setup(){
  Serial.begin(9660);
  matrix.begin(); 
  matrix.displayClear();
  Serial.println("Enter the text to display: ");
}

void loop(){
    if (Serial.available()){
      data = Serial.readStringUntil('\n');
    }

    else if (data != ""){
      matrix.setTextAlignment(PA_CENTER);
      matrix.setInvert(false);
      matrix.print(data);
      delay(1000);
      matrix.setInvert(true);
      matrix.print(data);
      delay(1000);
    }
}
