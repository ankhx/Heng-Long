//Arduino based controller for servo recoil, gun flash, and barrel smoke
//componnents: arduino nano, l298n DollaTek motor driver or equivalent, generic Heng Long smoke unit, 9g servo SG90, 220 and 10k resistors, standard LED, cables/connectors
//IMPORTANT: remove the capacitor from the motor 
//you need to bridge CN6


//you need to download and install VarSpeedServo library
#include <VarSpeedServo.h>
VarSpeedServo myservo;

//LED attached to pin 7 with 220 Ohm resistor
#define LED 7

//relay attached to pin 3
const int TRIGGER = 3; 
int buttonState = 0; 

//motor driver attached to pins 5 and 6
//if motor attached to the driver is running in wrong direction, swap around motor wires

int motor1pin1 = 5;
int motor1pin2 = 6;


void setup() { 

  pinMode(LED, OUTPUT);
  pinMode(TRIGGER, INPUT);

 //servo attached to pin 4
  myservo.attach(4);

 //initial servo position, this can be adjusted 0-180
  myservo.write(30);

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
   
}
void loop(){ 
  //checking if fire button pressed
   buttonState = digitalRead(TRIGGER);
   if(buttonState == HIGH) {

  //turn on smoke motor, if working the other way around swap the cables or swap around HIGH and LOW below
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  //turn on LED
  digitalWrite(LED, HIGH);

  //activate servo; first number indicates new possition and can be adjusted 0-180, second indicates speed
  myservo.write(140,240,true);

  //turn LED off
  digitalWrite(LED, LOW); 

  //move servo back, again can be adjusted
  myservo.write(30,80,true); 


  //turn smoke motor off
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  
  }
   delay(10);
   
}
