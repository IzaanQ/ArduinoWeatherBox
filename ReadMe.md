//Izaan Qaiser
//11.11.20
//TEJ201-01
//Weather Box
//Weather Box is a little box that
//is controlled by an IR controlled servo motor
//and uses a DHT11 sensor and an LCD to show the 
//temperature of the surrounding area.
As the first plot isn't actual code, it is information about the compiler, and the general intent of the code.
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <dht.h>
#include <IRremote.h>
#include <Servo.h>


This block of code calls forward all libraries that are required to properly execute the code. 
Servo servo1;
LiquidCrystal_I2C lcd(0x27,20,4);  
dht DHT;
These three lines of code are used to somewhat re-define the library names, into something that can be used in the actual code, easily. 
int servoPin = 9;
const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
This block of code is used to state where the mechanical signal terminals of the code are located, and gives instructions to the IR receiver for when to decode a signal from its remote.
#define DHT11_PIN 4
This line of code is to let the user communicate to the arduino to pick up the DHT11s signal from pin 4.
void setup()
{
  servo1.attach(servoPin);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  lcd.init();                      
}
This block is the initial setup of the code. What happens here is consistent amongst the entire process, and stays the same. The first line indicates that in any place the code says servo1, it wants the line to refer to the servoPin definition, which is located at pin 9. The IR lines make the IR receiver blink when it receives a signal, and send signals to the program. The LCD line initialises the LCD.
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


This entire compilation dictates the part of the code that repeats over and over again. The first line prompts the IR receiver to decode any signal it receives, and to compare them to the hex code values given below. If any of the signals picked up by the IR receiver correlate with the hex code values in the 2 blocks below, then the specified instruction on what the servo motors orientation should be follows the press of the button, in a matter of seconds. The line of code after the two blocks addressing the hex code values, tells the IR receiver to stay prompt for any other signals. 



This block of the code is the portion that writes the DHT11 reading to the LCD. The first line tells the arduino to read the integer value from the DHT11 sensor at pin 11. The second line initialises the backlight of the LCD. The third line sets the placement of where the first line of text should be, and the 4th says what the LCD should print in its first line. Lines 5 to 6 are the same,  just with the bottom line.  Line 7 tells the program to print the DHT temperature reading, and line 8 tells the program to add a "°C" at the end, on the LCD. 

