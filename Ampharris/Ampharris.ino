//Main file for the Arduino Source Code of the Ampharris ROD.
//Group: 183, Author: Koen Degeling.

// pin number of on-board LED
int ledPin = 13;

// Pulse Width Modulation (PWM) pins
int PWM1 = 3;
int PWM2 = 5;
int PWM3 = 6;
int PWM4 = 11;

#include <Servo.h>  // standard servo library

Servo servoX; // declare servo objects
Servo servoY;

int posY = 90; // initial servo posititions in degree
int posX = 90;

int servoPinX = A0; // arduino pins used to connect servo control signals
int servoPinY = A1;

// setup() is only run once
void setup() {
  Serial1.begin(115200); // ethernet cable or WiFi

  servoX.attach(servoPinX);
  servoY.attach(servoPinY);

  servoX.write(posX); // move to middle position
  servoY.write(posY);
  // all outputs to zero
  analogWrite(PWM1,0);
  analogWrite(PWM2,0);
  analogWrite(PWM3,0);
  analogWrite(PWM4,0);


  // read the input buffer until it is empty
  // any character in the buffer is ignored
  while (Serial1.available())
     Serial1.read();
}

// the commands in loop() are repeated forever
void loop() {
	if(Serial1.available() > 0) {
		char Command = Serial1.read();
		// if a w,z,a or d is pressed servos move with a step of
		// 5 degrees.
		// s moves to mid position
		switch(Command) {
			case 'w':
				posY = posY + 5;
				servoY.write(posY);
				break;
			case 'z':
				posY = posY - 5;
				servoY.write(posY);
				break;
			case 'a':
				posX = posX + 5;
				servoX.write(posX);
				break;
			case 'd':
				posX = posX - 5;
				servoX.write(posX);
				break;
			case 's':
				posX = 90;
				servoX.write(posX);
				posY = 90;
				servoY.write(posY);
				break;
			// if 5 kill all outputs
			case '5':
				analogWrite(PWM1,0);
				analogWrite(PWM2,0);
				analogWrite(PWM3,0);
				analogWrite(PWM4,0);
				break;
            // in other cases switch to all combinations of forward and reverse
            // 255 means full speed
			case '8':
				analogWrite(PWM1,255);
				analogWrite(PWM2,0);
				analogWrite(PWM3,255);
				analogWrite(PWM4,0);
				break;
            case '2':
            	analogWrite(PWM1,0);
            	analogWrite(PWM2,255);
            	analogWrite(PWM3,0);
            	analogWrite(PWM4,255);
            	break;
            case '4':
            	analogWrite(PWM1,255);
            	analogWrite(PWM2,0);
            	analogWrite(PWM3,0);
            	analogWrite(PWM4,255);
            	break;
            case '6':
            	analogWrite(PWM1,0);
            	analogWrite(PWM2,255);
            	analogWrite(PWM3,255);
            	analogWrite(PWM4,0);
            	break;
    }
  }
}
