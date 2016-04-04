
void leaf_drop()
{

  delay(500);
  analogWrite(grip_motor_frw,0);
  analogWrite(grip_motor_rev,150);

  while(analogRead(A8) < 100)
  {
    //Serial.println("black");
    //      Serial.println(analogRead(A8));
  }

  while(analogRead(A8) >= 100) 
  {
    //Serial.println("white");
    //      Serial.println(analogRead(A8));
  }

  //Serial.println("Motor stop");

  analogWrite(grip_motor_frw,0);
  analogWrite(grip_motor_rev,0);



  digitalWrite(grip,0);
  delay(500);

  digitalWrite(grip,1);

  delay(500);

  analogWrite(grip_motor_frw,150);
  analogWrite(grip_motor_rev,0);

  while(analogRead(A8) < 100)
  {
    //Serial.println("black");
    //      Serial.println(analogRead(A8));
  }

  while(analogRead(A8) >= 100) 
  {
    //Serial.println("white");
    //      Serial.println(analogRead(A8));
  }

  //Serial.println("Motor stop");

  analogWrite(grip_motor_frw,0);
  analogWrite(grip_motor_rev,0);

  path++;
}

