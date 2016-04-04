void reverse(int dist)
{ 
  int total_pulses = dist / one_pulse;


  while((total_pulses + pulses_right)>0)
  {

    analogWrite(left_mot_fwd,0);
    analogWrite(left_mot_rev,100);
    analogWrite(right_mot_fwd,0);
    analogWrite(right_mot_rev,100);

  }

  while((total_pulses + pulses_right)<=0)
  {

    stopper();
    delay(250);
    pulses_right=0;
    pulses_left=0;
    path++;

  }

}







