//Date: 09/12/21
//Bluetooth car
//Author: Jawahar B
#include <SoftwareSerial.h>

String readString;

//#define HL  3
#define trigPin 2
#define echoPin 3
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define buzzer 8
long duration, distance;
//RX 0
// TX 1
void setup() {
pinMode(IN1,OUTPUT);   //left motors forward
pinMode(IN2,OUTPUT);   //left motors reverse
pinMode(IN3,OUTPUT);   //right motors forward
pinMode(IN4,OUTPUT);   //right motors reverse
pinMode(trigPin, OUTPUT); // Set Trig Pin As O/P To Transmit Waves
pinMode(echoPin, INPUT);
pinMode(buzzer,OUTPUT);

SoftwareSerial mySerial(0, 1); // RX TX
Serial.begin(9600);
 
}
 
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH); // Transmit Waves For 10us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // Recieve Reflected Waves
  distance = duration / 58.2; // Get Distance
  delay(10);
  if (distance > 20) // Condition For Absence Of Obstacle            
  {
  while (Serial.available()) {
    delay(10);  //small delay to allow input buffer to fill

    char c = Serial.read();  //gets one byte from serial buffer
    if (c == ',') {
      break;
    }  //breaks out of capture loop to print readstring
    readString += c; 
  } //makes the string readString  

 
if(readString == 'forward'){            //move forward(all motors rotate in forward direction)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(5000);

}
 
else if(readString == 'backward'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(5000);
}
 
else if(readString == 'left'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(1000);
}
 
else if(readString == 'right'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(1000);
}
 
else if(readString == 'stop'){      //STOP (all motors stop)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

delay(1);
}

else {      //STOP (all motors stop)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(buzzer, HIGH);
}
delay(5);
}
