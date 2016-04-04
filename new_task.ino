void task1()
{

//  start();
//  delay(500);
  forward(277);


  delay(200);
  forward(130);

  delay(200);

  left(68);
  delay(200);

  forward(142);

  arm_left(105);
  
  delay(200);

  leaf_drop();
  
  arm_right(195);
  
  delay(200);

  leaf_drop();
  
  delay(200);

  arm_left(100);
  
  right(15);
  
  delay(200);
  
  forward(190);

  delay(200);

  arm_right(52);
 
  leaf_drop();
 
  delay(200);

  arm_left(40);
 
  delay(1000);
  stopper(); 
} 



//----------------------------------task 2---------------------------------





void task2()
{

  //      start();
  //      path=2;   


  line_follow_blue();                                                //      node 1 reached

  //---------  path 2 -------------


  forward(110);

  analogWrite(left_mot_fwd,70);
  analogWrite(left_mot_rev,0);
  analogWrite(right_mot_fwd,68);
  analogWrite(right_mot_rev,0);

  while(yash<=1000)
  {
    yash=(analogRead(A9)+analogRead(A4));                        //         node 2
  }

  stopper();
  pulses_right=0;



  forward(25);
  left(65);                                                      //      green line  detected

  stopper();
  pulses_right=0;



  //---------  path 3 -------------





  int sum_g=0;
  while(flag_l==1)
  {
    line_follow_green(); 

    if(flag_l==1)
    {
      ring_detect();

    }  

    if(flag_l==0)
    {
      arm_left(94);
      delay(100);
      leaf_drop();
      arm_right(187);
      delay(100);
      leaf_drop();
      flag_l=2;
      arm_left(93);
    }
  }
  while(sum_g<1000)
  {
    line_follow_green();
    sum_g = analogRead(A9)+ analogRead(A4);
  }
  stopper();
  pulses_right=0;
  forward(2);
  delay(100);
  right(75);
  delay(100);
  forward(50);
  stopper();
  path=6;

  //----------------  path 4 -------------------


  sum_g=0;
  while(sum_g<1000)
  {
    line_follow_green(); 

    sum_g = analogRead(A9)+ analogRead(A4);
  }


  //----------------  path 5 -------------------

  pulses_right=0;
  forward(10);
  right(87);
  forward(80);
  arm_left(87);
  leaf_drop();
  arm_right(87);
  stopper();


  //------------------- bud collect ---------------- 

  reverse(75);
  left(181);

  forward(150);
  left(75);
  analogWrite(left_mot_fwd,0);
  analogWrite(left_mot_rev,200);
  analogWrite(right_mot_fwd,0);
  analogWrite(right_mot_rev,200);
  delay(2000);
  stopper();
  pulses_right=0;
  forward(20);
  right(92);

  temp_b=1;
  while(temp_b==1)
  {
    analogWrite(left_mot_fwd,120);
    analogWrite(left_mot_rev,0);
    analogWrite(right_mot_fwd,118);
    analogWrite(right_mot_rev,0);
    bud_detect();
  }
  stopper();
  delay(3000);
  digitalWrite(grip,0);
}





