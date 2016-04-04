int cm_l=0,cm_r=0,cm_u=0;

#include <Ultrasonic.h>

#define TRIGGER_PIN1  22
#define ECHO_PIN1  24

Ultrasonic ultrasonic1(TRIGGER_PIN1, ECHO_PIN1);

#define TRIGGER_PIN2  28
#define ECHO_PIN2  30

Ultrasonic ultrasonic2(TRIGGER_PIN2, ECHO_PIN2);

#define TRIGGER_PIN3  46
#define ECHO_PIN3  47  

Ultrasonic ultrasonic3(TRIGGER_PIN3, ECHO_PIN3);

#define TRIGGER_PIN4  31
#define ECHO_PIN4  33

Ultrasonic ultrasonic4(TRIGGER_PIN4, ECHO_PIN4);

void bud_detect()
{
  long microsec = ultrasonic1.timing();
  cm = ultrasonic1.convert(microsec, Ultrasonic::CM);
  Serial.print("cm=");
  Serial.println(cm);
  if(cm>5 && cm<20)
  { 
    Serial.println("in range");
    stopper();
    Serial.println(cm);
    for(int x=0;x<1;x++)
    {
      stopper();
      delay(500);
      bud_pick();
      
    }
    temp_b++;
    Serial.println(temp);
  }
}


void leaf_detect()
{  

  long microsec = ultrasonic1.timing();
  cm = ultrasonic1.convert(microsec, Ultrasonic::CM);
  if(cm>5 && cm<15)

  { 
    for(int x=0;x<1;x++)
    {
      
      leaf_pick();
      
    }
    temp++;

  }
}




void ring3()
{
  int r3=0;
  while(r3==0)
  {
    long microsec = ultrasonic1.timing();
    cm = ultrasonic1.convert(microsec, Ultrasonic::CM);
    Serial.print("cm=");
    Serial.println(cm);
    analogWrite(left_mot_fwd,0);
    analogWrite(left_mot_rev,70);
    analogWrite(right_mot_fwd,68);
    analogWrite(right_mot_rev,0);
    if(cm>45 && cm<50)
    { 
      Serial.println("in range");
      stopper();
      Serial.println(cm);
      for(int x=0;x<1;x++)
      {
        stopper();
        leaf_drop();
      }
      r3=1;

    }

  }
}




void ring_detect()
{

  long microsec = ultrasonic2.timing();
  cm_l = ultrasonic2.convert(microsec, Ultrasonic::CM);
  if(flag_l==1)
  { 
    if(cm_l>15 && cm_l<=30)
    {    

      flag_l=0;
      stopper();
      delay(500);

    }

  }


}
void last_ring()
{  

  long micro = ultrasonic3.timing();
  cm_r = ultrasonic3.convert(micro, Ultrasonic::CM);
  if(flag_r==1)
  {
    if(cm_r >= 5 && cm_r <= 25)
    {    
      flag_r=0;
      stopper();
      delay(2000);
    }
  }
}

void ring_leaf()
{
  long microsec = ultrasonic4.timing();
  cm_u = ultrasonic4.convert(microsec, Ultrasonic::CM);
  if(cm_u >= 10 && cm_u <= 40)
  {    
    flag_u=0;
    stopper();
    delay(500);

  }
}


















