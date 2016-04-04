int diff=0,speedl=0;
void forward(int dist)
{ 
  int total_pulses = dist / one_pulse;
  //Serial.println(total_pulses);

  while((total_pulses-pulses_right)>0)
  {
    
    
    analogWrite(right_mot_fwd,120);
    analogWrite(right_mot_rev,0);
    Serial.println((pulses_right - pulses_left));
  
    
   if((total_pulses-pulses_left)>0)
  {
        
      if(pulses_right > pulses_left)
      {
        diff = (pulses_right - pulses_left);
        speedl=120+diff;
        analogWrite(left_mot_fwd,speedl);
        analogWrite(left_mot_rev,0);
        
    
    
      }
      else if(pulses_right < pulses_left)
      {
        
        diff=pulses_right - pulses_left;
        speedl=120 + diff;
        analogWrite(left_mot_fwd,speedl);
        analogWrite(left_mot_rev,0);
        
      
    }
  }
  
      else if(pulses_right == pulses_left)
      {
        analogWrite(left_mot_fwd,120);
        analogWrite(left_mot_rev,0);
     
      
  }
  
//    if(temp<1)
//    {
//      leaf_detect();
//    }
    
  }
  stopper();
  
  Serial.println("stop");
 
  while(pulses_right != pulses_left)
  {
    Serial.println((pulses_right - pulses_left));
  while(pulses_right > pulses_left)
  {
    Serial.println("right > left");
    Serial.println((pulses_right - pulses_left));
    analogWrite(left_mot_fwd,50);
    analogWrite(left_mot_rev,0);
    analogWrite(right_mot_fwd,0);
    analogWrite(right_mot_rev,0);
  }
     analogWrite(right_mot_fwd,0);
    analogWrite(right_mot_rev,0);
    analogWrite(left_mot_fwd,0);
    analogWrite(left_mot_rev,0);
  
  while(pulses_right < pulses_left)
  {
    Serial.println("right < left");
    Serial.println((pulses_right - pulses_left));
    analogWrite(right_mot_fwd,50);
    analogWrite(right_mot_rev,0);
    analogWrite(left_mot_fwd,0);
    analogWrite(left_mot_rev,0);
  }
     analogWrite(right_mot_fwd,0);
    analogWrite(right_mot_rev,0);
    analogWrite(left_mot_fwd,0);
    analogWrite(left_mot_rev,0);
  }
    

  Serial.println("end ");
 
    stopper();
   
    pulses_right=0;
    pulses_left=0;
    path++;
 
}







