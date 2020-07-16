#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  mtr_S1_C1_1,     left,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     right,         tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
void sonarSensorRead()
{
    int k,l=0;
    for(k=0;k<160;k+=7)
    {
        l+=5;
        servo[servo1]=k;
        wait1Msec(1000);
        int j=SensorValue(sonar);
        nxtDisplayCenteredTextLine(0,"Reading for %d degrees",l);
        nxtDisplayBigStringAt(40,30,"%d",j);
        wait1Msec(1000);
    }
}
task main()
{
    int speed2=10,speed1=15;
	nMotorEncoder[motorA]=0;
  nMotorEncoder[motorC]=0;
	//move straight for 164cms
    while(nMotorEncoder[motorB]<2520)
    {
        motor[right]=speed1;
        motor[left]=speed1;
    }

	nMotorEncoder[motorC]=0;
// turn right by 90 degrees
    while(nMotorEncoder[motorC]>-801)
    {
        motor[right]=0;
        motor[left]=speed2;
    }

        nMotorEncoder[motorB]=0;
        while(nMotorEncoder[motorB]<2620)
    {
        motor[right]=speed1;
        motor[left]=speed1;
    }

    nMotorEncoder[motorB]=0;
    while(nMotorEncoder[motorB]<821)
    {
        motor[right]=speed2;
        motor[left]=0;
    }

	motor[right]=0;
	motor[left]=0;
	wait1Msec(100);
    servo(servo1)=75;
    wait1Msec(3000);

//stop at red line
    while(SensorValue(light)>48)
    {
        motor[right]=speed2;
        motor[left]=speed2;
    }

        motor[right]=0;
        motor[left]=0;
        wait1Msec(500);
        sonarSensorRead();
}

