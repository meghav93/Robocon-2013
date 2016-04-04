void wait_for_manual()
{
  int ack=1;
  while(ack=1)
  {
    if(Serial.available())
    {
      if(Serial.read()<100)
      { 
        ack=0;
      }
      else {
        ack=1;
      }
    }
  }
}

