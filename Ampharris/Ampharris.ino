//Main file for the Arduino Source Code of the Ampharris ROD.
//Group: 183, Author: Koen Degeling.

//Include:
#include <Servo.h>
// pin number of on-board LED
int ledPin = 13;

// We initialise the pins we use for PWM, used for the
// motors. The frequency of the PWM determines the resulting
// voltage to the motors.
int PWM1 = 3;
int PWM2 = 5;
int PWM3 = 6;
int PWM4 = 11;

//Servo objects with their own function for control
Servo servoX;
Servo servoY;

// initial servo posititions in degree
int posY = 90;
int posX = 90;
//Initialise the servo pins
int servoPinX = A0;
int servoPinY = A1;

// setup() is only run once
void setup() {
  Serial1.begin(115200); // ethernet cable or WiFi

  //Setup servo objects
  servoX.attach(servoPinX);
  servoY.attach(servoPinY);

  //Servo function to write the position of the servo
  servoX.write(posX);
  servoY.write(posY);
  /* We start with all motors of, so we write 0 to all
   * PWM pins */
  analogWrite(PWM1,0);
  analogWrite(PWM2,0);
  analogWrite(PWM3,0);
  analogWrite(PWM4,0);


  // read the input buffer until it is empty
  // any character in the buffer is ignored
  while (Serial1.available())
     Serial1.read();
}

/* Repeated code. In here we declare stuff for the control of the ROD, functions might be extended
 * to include better controls, better control over the PWM of the motors, etc.
 */
void loop() {
	//TODO: Write code for the motors that will open the hatch,
	//      and code for the motors that control the arm.
	if(Serial1.available() > 0) { //If we have a character in our buffer, enter if-statement
		char Command = Serial1.read(); //Read sumbitted character
		switch(Command) { /*Here we make a switch-case, wasdz is for controlling the servo,
		 	 	 	 	 	*the numpad keys are used for controlling the DC-motors, this should be adapted
		 	 	 	 	 	*as our ROD will use the 2 big wheels to turn */
			case 'w': //Use .write to write the new position of the servo w=+y,z=-y,a=+x,d=-x, s=reset
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
            /* Currently writes full speed to motors in the direction that is pressed
             * Should be changed such that more control is allowed over speed.
             */
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
