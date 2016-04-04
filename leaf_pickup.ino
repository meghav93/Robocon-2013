
void leaf_pick()
{
  //  Serial.println("leaf pick");
  digitalWrite(arm,1);        // arm down
  digitalWrite(grip,0);       // gripper open
  // Serial.println("grip open");
  delay(500);
  
 
  analogWrite(left_mot_fwd,120);
  analogWrite(left_mot_rev,0);
  analogWrite(right_mot_fwd,120);
  analogWrite(right_mot_rev,0);
 delay(500);
  stopper();
  digitalWrite(grip,1);      
  digitalWrite(arm,0);      

}

void bud_pick()
{
  //  Serial.println("leaf pick");
  digitalWrite(arm,1);        // arm down
  digitalWrite(grip,0);       // gripper open
  // Serial.println("grip open");
  delay(500);
  analogWrite(left_mot_fwd,90);
  analogWrite(left_mot_rev,0);
  analogWrite(right_mot_fwd,90);
  analogWrite(right_mot_rev,0);
  delay(500);
  stopper();
  digitalWrite(grip,1);      
  //Serial.println("grip close");
  delay(100);
  digitalWrite(arm,0);      
  //delay(1000);
}










