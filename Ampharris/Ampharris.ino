//Main file for the Arduino Source Code of the Ampharris ROD.
//Group: 183, Author: Koen Degeling.

//Include:
#include <Servo.h>
#include <TimerOne.h>
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
Servo servoLeft;
Servo servoRight;

// initial servo posititions in degree
int posY = 90;
int posX = 90;
int servoSpeedLeft = 90;
int servoSpeedRight = 90;
//Initialise the servo pins
int servoPinX = A0;
int servoPinY = A1;
int servoPinLeft = A2;
int servoPinRight = A3;
int speed = 255;

// setup() is only run once
void setup() {
  Serial1.begin(115200); // ethernet cable or WiFi
  Timer1.initialize(2000000); //We initialize the timer at 2 second
  //Setup servo objects
  servoX.attach(servoPinX);
  servoY.attach(servoPinY);
  servoLeft.attach(servoPinLeft);
  servoRight.attach(servoPinRight);

  //Servo function to write the position of the servo
  servoX.write(posX);
  servoY.write(posY);
  servoLeft.write(servoSpeedLeft);
  servoRight.write(servoSpeedRight);
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
void timerInterruptServo() { //Timer Interrupt for the Servos (Used to make ROD drive for a few seconds).
  servoSpeedLeft = 90;  //We set the servos to stop
  servoSpeedRight = 90; //We set the servos to stop
  servoLeft.write(servoSpeedLeft);
  servoRight.write(servoSpeedRight);
  Timer1.detachInterrupt(); //We detach the interrupt.
}
void timerInterruptDC1() { //Timer Interrupt for the DC motors, used to enable the DC motors for a few seconds.
  analogWrite(PWM1,0);
  analogWrite(PWM2,0);
  Timer1.detachInterrupt(); //We detach the interrupt.
}
void timerInterruptDC2() { //Timer Interrupt for the DC motors, used to enable the DC motors for a few seconds.
  analogWrite(PWM3,0);
  analogWrite(PWM4,0);
  Timer1.detachInterrupt(); //We detach the interrupt.
}
void loop() {
  //TODO: Write code for the motors that will open the hatch,
  //      and code for the motors that control the arm.
  if(Serial1.available() > 0) { //If we have a character in our buffer, enter if-statement
    char Command = Serial1.read(); //Read sumbitted character
    switch(Command) { /*Here we make a switch-case, wasdz is for controlling the servo,
              *the numpad keys are used for controlling the DC-motors, this should be adapted
              *as our ROD will use the 2 big wheels to turn */
              /* Controls: Num-Pad to control the wheels. Use WASDZ to control the gimbal
               * attached to the camera.
               */
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
      /* We write to the Servo's that cotrol the weels.
       * speed controls the speed at which they turn.
       */
      case '8': //Num-pad keys are used to control ROD, speed, FORWARD and BACKWARD decide the direction.
          servoSpeedLeft = 0;
          servoLeft.write(servoSpeedLeft);
          servoSpeedRight = 0;
          servoRight.write(servoSpeedRight);
          break;
      case '5': //We turn off all motors (brake)
          servoSpeedLeft = 90;
          servoLeft.write(servoSpeedLeft);
          servoSpeedRight = 90;
          servoRight.write(servoSpeedRight);
          break;
      case '2': //We go reverse
          servoSpeedLeft = 180;
          servoLeft.write(servoSpeedLeft);
          servoSpeedRight = 180;
          servoRight.write(servoSpeedRight);
          break;
      case '4': //We turn to the left.
          servoSpeedLeft = 90;
          servoLeft.write(servoSpeedLeft);
          servoSpeedRight = 0;
          servoRight.write(servoSpeedRight);
          break;
      case '6': //We turn to the right;
          servoSpeedLeft = 0;
          servoLeft.write(servoSpeedLeft);
          servoSpeedRight = 90;
          servoRight.write(servoSpeedRight);
          break;
      //Code for extending the ramp and using the arm.
      case 'p':
          analogWrite(PWM1, 255);
          analogWrite(PWM2, 0);
          Timer1.attachInterrupt(timerInterruptDC1, 5000000);
          break;
      case 'o':
          analogWrite(PWM1, 0);
          analogWrite(PWM2, 255);
          Timer1.attachInterrupt(timerInterruptDC1, 5000000);
          break;
      case 'l':
          analogWrite(PWM3, 255);
          analogWrite(PWM4, 0);
          Timer1.attachInterrupt(timerInterruptDC2, 5000000);
          break;
      case 'k':
          analogWrite(PWM3, 0);
          analogWrite(PWM4, 255);
          Timer1.attachInterrupt(timerInterruptDC2, 5000000);
          break;
      case 'y': //forward
          servoSpeedLeft = 0;
          servoLeft.write(servoSpeedLeft);
          servoSpeedRight = 0;
          servoRight.write(servoSpeedRight);

          break;
      case 'g': //left
          servoSpeedLeft = 90;
          servoLeft.write(servoSpeedLeft);
          servoSpeedRight = 0;
          servoRight.write(servoSpeedRight);
          Timer1.attachInterrupt(timerInterruptServo, 5000000);
          break;
      case 'h': //backwards
          servoSpeedLeft = 180;
          servoLeft.write(servoSpeedLeft);
          servoSpeedRight = 180;
          servoRight.write(servoSpeedRight);
          Timer1.attachInterrupt(timerInterruptServo, 5000000);
          break;
      case 'j': //right
          servoSpeedLeft = 0;
          servoLeft.write(servoSpeedLeft);
          servoSpeedRight = 90;
          servoRight.write(servoSpeedRight);
          Timer1.attachInterrupt(timerInterruptServo, 5000000);
          break;
    }
  }
}
