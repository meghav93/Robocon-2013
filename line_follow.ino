



void line_follow_blue()
{
  int sum=0;
  while(sum<1200)
  {

    right1 =map(analogRead(A0),a_min,a_max,150,0);
    left1  =map(analogRead(A3),d_min,d_max,150,0);

    right2 =map(analogRead(A1),b_min,b_max,0,150);
    left2  =map(analogRead(A2),c_min,c_max,0,150);

    right0 = (2*right1 + right2)/3; 
    left0  = (2*left1 + left2)/3;
    right0=constrain(right0,0,150);
    left0=constrain(left0,0,150);
    sum=(analogRead(A0)+analogRead(A3));
    Serial.println(sum);


    analogWrite(left_mot_fwd,left0);
    analogWrite(left_mot_rev,0);
    analogWrite(right_mot_fwd,right0); 
    analogWrite(right_mot_rev,0);


    if(temp<1)
    {
      leaf_detect();
    }
  }
  if(sum > 1200)
  {

    stopper();
    pulses_right=0;
    path++;

  }
}






void line_follow_green()
{

  right_g1 =map(analogRead(A4),x_min,x_max,100,0);
  left_g1  =map(analogRead(A9),w_min,w_max,100,0);

  right_g2 =map(analogRead(A5),p_min,p_max,130,0);
  left_g2  =map(analogRead(A6),z_min,z_max,130,0);

  right_g0 = (2*right_g1 + right_g2)/3; 
  left_g0  = (2*left_g1 + left_g2)/3;
  analogWrite(left_mot_fwd,left_g0);
  analogWrite(left_mot_rev,0);
  analogWrite(right_mot_fwd,right_g0); 
  analogWrite(right_mot_rev,0);
}





