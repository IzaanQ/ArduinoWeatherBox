//Izaan Qaiser
//11.11.20
//TEJ201-01
//Weather Box
//Weather Box is a little box that
//is controlled by an IR controlled servo motor
//and uses a DHT11 sensor and an LCD to show the 
//temperature of the surrounding area.

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <dht.h>
#include <IRremote.h>
#include <Servo.h>

Servo servo1;
LiquidCrystal_I2C lcd(0x27,20,4);  
dht DHT;

int servoPin = 9;
const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define DHT11_PIN 4

void setup()
{
  servo1.attach(servoPin);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  lcd.init();                      
}

void loop(){
    if (irrecv.decode(&results)){

        switch(results.value){
          case 0xFF22DD: 
          servo1.write(90);
          delay(1000);
          }

        switch(results.value){
          case 0xFF02FD:
              servo1.write(0);
          delay(1000);
          }

        irrecv.resume(); 
    }
      int chk = DHT.read11(DHT11_PIN);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("The temperature ");
  lcd.setCursor(0,1);
  lcd.print("is ");
  lcd.println(DHT.temperature);
  lcd.print("°C");
}


