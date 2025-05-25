
#include <Wire.h>
#include "eGizmo_PBOT2018.h"

eGizmo_PBOT2018 PBOT;
int SP1 = 67;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  PBOT.BEGIN();
  PBOT.ALLON();
  PBOT.SPEED(MOTOR_BOTH, SP1);

}
void loop() 
{
  if(PBOT.LS1_LEFT() == LOW && PBOT.LS3_RIGHT() == LOW)
  {
    FORWARD();
  }
  if(PBOT.LS1_LEFT() == LOW && PBOT.LS3_RIGHT() == HIGH)
  {
    TURN_RIGHT();
  }
  if(PBOT.LS1_LEFT() == HIGH && PBOT.LS3_RIGHT() == LOW)
  {
    TURN_LEFT();
  }
  if(PBOT.LS1_LEFT() == LOW && PBOT.LS2_CENTER() == LOW && PBOT.LS3_RIGHT() == LOW)
  {
    REVERSE();
    delay(86);
  }
  //UNCOMMENT THIS FOR STOPPING POINT
 /* if(PBOT.LS1_LEFT() == HIGH && PBOT.LS3_RIGHT() == HIGH)
  {
    STOP();
  }*/
}
void FORWARD(void)
{
  PBOT.DIRECTION(MOTOR_BOTH,MOTOR_FWD);
  PBOT.SPEED(MOTOR_BOTH,SP1);
}
void REVERSE()
{
  PBOT.DIRECTION(MOTOR_BOTH, MOTOR_REV);
  PBOT.SPEED(MOTOR_BOTH,SP1);
}
void TURN_LEFT()
{
  PBOT.DIRECTION(MOTOR_B, MOTOR_FWD);
  PBOT.SPEED(MOTOR_B, SP1);
  PBOT.DIRECTION(MOTOR_A, MOTOR_REV);
  PBOT.SPEED(MOTOR_A, 0);
}
void TURN_RIGHT()
{
  PBOT.DIRECTION(MOTOR_A, MOTOR_FWD);
  PBOT.SPEED(MOTOR_A, SP1);
  PBOT.DIRECTION(MOTOR_B, MOTOR_REV);
  PBOT.SPEED(MOTOR_B, 0);
}
void STOP()
{
  PBOT.SPEED(MOTOR_BOTH,0);
}
