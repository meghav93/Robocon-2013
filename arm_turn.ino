void arm_left(int angle)
{
  //Serial.println("lef");
  int total_pulses = angle *arm_degree;
  //Serial.println(total_pulses);
  arm_pulse=0;
  while((arm_pulse - total_pulses)<0)
  { 
    // Serial.println(arm_pulse);
    analogWrite(arm_motor_frw,130);
    analogWrite(arm_motor_rev,0);

  }
  while((arm_pulse - total_pulses)>0)
  { //Serial.println("more");
    analogWrite(arm_motor_frw,0);
    analogWrite(arm_motor_rev,130);
  }
  while((arm_pulse - total_pulses)==0)
  { 
    //Serial.println("end");

    analogWrite(arm_motor_frw,0);
    analogWrite(arm_motor_rev,0); 
    delay(250);
    arm_pulse=0;
    path++;  

  }
}



//----------------------------------------------------------------------------------



void arm_right(int angle)
{
  arm_pulse=0;
  int total_pulses = angle * arm_degree;



  while((arm_pulse + total_pulses)>0)
  {
    analogWrite(arm_motor_frw,0);
    analogWrite(arm_motor_rev,130);
  }
  while((arm_pulse + total_pulses)<0)
  {
    analogWrite(arm_motor_frw,130);
    analogWrite(arm_motor_rev,0);
  }
  while((arm_pulse + total_pulses)==0)
  {
    analogWrite(arm_motor_frw,0);
    analogWrite(arm_motor_rev,0);
    delay(250);
    arm_pulse=0;
    path++;  
  }
}



