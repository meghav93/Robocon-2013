void left(int angle)
{
  //Serial.println("left");
  int total_pulses = angle*one_degree;

  while((total_pulses-pulses_right)>0)

  {  
    //    Serial.println("total_pulses:");
    //    Serial.println(total_pulses);
    //    Serial.println("pulses_right:");
    //    Serial.println(pulses_right);
    analogWrite(left_mot_fwd,0);
    analogWrite(left_mot_rev,100);
    analogWrite(right_mot_fwd,100);
    analogWrite(right_mot_rev,0);
  }
//  if((total_pulses-pulses_right)<0 )
//  {
//    Serial.println("more");
//    Serial.println(pulses_right);
//    analogWrite(left_mot_fwd,0);
//    analogWrite(left_mot_rev,0);
//    analogWrite(right_mot_fwd,0);
//    analogWrite(right_mot_rev,0);
//    path++;
//  }


  if((total_pulses - pulses_right) <= 0)
  { 
    //Serial.println("condition??????????????????");
    stopper();
    digitalWrite(13,1);
    delay(250);
    pulses_right=0;
    pulses_left=0;
    path++;
    //Serial.println(path);    
  }

}


//-----------------------------------------------------------------------------------------
void right(int angle) 
{ 
  //Serial.println("right");
  int total_pulses = angle * one_degree;
  while((total_pulses+pulses_right)>0)
  {
    analogWrite(left_mot_fwd,60);
    analogWrite(left_mot_rev,0);
    analogWrite(right_mot_fwd,0);
    analogWrite(right_mot_rev,60);
  }
//  if((total_pulses+pulses_right)<0 )
//  {
//    analogWrite(left_mot_fwd,0);
//    analogWrite(left_mot_rev,0);
//    analogWrite(right_mot_fwd,0);
//    analogWrite(right_mot_rev,0);
//    path++;
//  }


  if((pulses_right+total_pulses)<=0)
  { 
    //Serial.println("condition??????????????????");
    stopper();
    delay(250);
    pulses_right=0;
    pulses_left=0;
    path++;
    //Serial.println(path);
  }
}




