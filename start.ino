void start()
{
  arm_right(90);

  analogWrite(grip_motor_frw,0);
  analogWrite(grip_motor_rev,150);

  while(analogRead(A8) < 100);

  while(analogRead(A8) >= 100); 

  analogWrite(grip_motor_frw,0);
  analogWrite(grip_motor_rev,0);

  forward_start(25);

  right(45);

  forward_start(22);

  left(45);
  path=2;
}

//-----------------------------------------------------------------------

void forward_start(int dist)
{
  int total_pulses = dist / one_pulse;
  while((total_pulses-pulses_right)>0)
  {
    analogWrite(left_mot_fwd,150);
    analogWrite(left_mot_rev,0);
    analogWrite(right_mot_fwd,150);
    analogWrite(right_mot_rev,0);
  }
  while((total_pulses - pulses_right)<=0)
  {

    stopper();
    delay(200);
    pulses_right=0;

  }
}








