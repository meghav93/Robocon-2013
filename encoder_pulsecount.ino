//-----------------------------right motor---------------------------------------


void doEncoderA()
{ 
  if (digitalRead(encoder0PinA) == HIGH) 
  { 

    if (digitalRead(encoder0PinB) == LOW) 
    {  
      pulses_right = pulses_right + 1;              // CW
    } 
    else 
    {
      pulses_right = pulses_right - 1;              // CCW
    }
  }
}



void doEncoderB()
{ 

  if (digitalRead(encoder0PinB) == HIGH) 
  {   

    if (digitalRead(encoder0PinA) == HIGH) 
    {  
      pulses_right = pulses_right + 1;             // CW
    } 
    else 
    {
      pulses_right = pulses_right - 1;             // CCW
    }
  }


}



//-----------------------------arm motor---------------------------------------


void doEncoderC()
{ 
  if (digitalRead(encoder0PinC) == HIGH) 
  { 

    if (digitalRead(encoder0PinD) == LOW) 
    {  
      arm_pulse = arm_pulse + 1;              // CW
    } 
    else 
    {
      arm_pulse = arm_pulse - 1;              // CCW
    }
  }
}



void doEncoderD()
{ 

  if (digitalRead(encoder0PinD) == HIGH) 
  {   

    if (digitalRead(encoder0PinC) == HIGH) 
    {  
      arm_pulse = arm_pulse + 1;             // CW
    } 
    else 
    {
      arm_pulse = arm_pulse - 1;             // CCW
    }
  }


}

//------------------------ left enc

void doEncoderX()
{ 
  if (digitalRead(encoder0PinX) == HIGH) 
  { 

    if (digitalRead(encoder0PinY) == LOW) 
    {  
      pulses_left = pulses_left + 1;              // CW
    } 
    else 
    {
      pulses_left = pulses_left - 1;              // CCW
    }
  }
}



void doEncoderY()
{ 

  if (digitalRead(encoder0PinY) == HIGH) 
  {   

    if (digitalRead(encoder0PinX) == HIGH) 
    {  
      pulses_left = pulses_left + 1;             // CW
    } 
    else 
    {
      pulses_left = pulses_left - 1;             // CCW
    }
  }


}







