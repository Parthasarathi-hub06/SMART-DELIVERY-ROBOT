#speed and zone

void Serial_bt_Read()
{
 Serial_bt_Chh = Serial.read();
 if(Serial_bt_Chh == 'a')
 {
  }

}

void Serial_bt_Write(String value1, String value2, String value3, String value4, String value5, String value6)
{
  values[0] = "S1:" + value1;
  values[1] = "S2:" + value2;
  values[2] = "S3:" + value3;
  values[3] = "S4:" + value4;
  values[4] = "S5:" + value5;
  values[5] = "S6:" + value6;
}

void sendBluetoothData()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= Send_interval)
  {
    previousMillis = currentMillis;
    if (sendIndex < bt_Sensor_Count)
    {
      Serial.println(values[sendIndex]); // Send via Bluetooth (HC-05 uses Serial)
      sendIndex++;
      if(sendIndex == bt_Sensor_Count)
      {
        sendIndex = 0; // reset sending
      }
    }
  }
}
int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}
void lcdprint(String l1, String l2) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(l1);
  lcd.print("                   ");
  lcd.setCursor(0,1);
  lcd.print(l2);
  lcd.print("                   ");
  interval();
}

void interval() {
  delay(1000);
  lcd.clear();
}
// Bluetooth Data Based Motor Controller 
void DCMotorCondition()
{
  if (Serial.available())
  {
    chh = Serial.read();
   // Serial.print("Received = ");
   // Serial.println(chh);

    if (chh == 'a')
    {
      MotorStopCmd();
      MotorForwardCmd();
      lcd.setCursor(0,1);
      lcd.print("FORWARD       ");
    }

    else if (chh == 'b')
    {
      MotorStopCmd();
      MotorReverseCmd();
      lcd.setCursor(0,1);
      lcd.print("REVERSE       ");
    }

    else if (chh == 'c')
    {
      MotorStopCmd();
      MotorLeftCmd();
      lcd.setCursor(0,1);
      lcd.print("LEFT          ");
    }

    else if (chh == 'd')
    {
      MotorStopCmd();
      MotorRightCmd();
      lcd.setCursor(0,1);
      lcd.print("RIGHT         ");
    }

    else if (chh == 'e')
    {
      MotorStopCmd();
      lcd.setCursor(0,1);
      lcd.print("STOP          ");
    }

    // Speed Increase
    else if (chh == '+')
    {
      Mspeed += 1;
      if (Mspeed > 255) Mspeed = 255;
      DisplaySpeed();
    }

    // Speed Decrease
    else if (chh == '-')
    {
      Mspeed -= 1;
      if (Mspeed < 0) Mspeed = 0;
      DisplaySpeed();
    }

    // Servo
    else if (chh == 'z')
    {
      digitalWrite(Relay_Pin,HIGH);
      lcdprint("BOX DOOR", "OPEN");
    }

    else if (chh == 'x')
    {
      digitalWrite(Relay_Pin,LOW);
      lcdprint("BOX DOOR", "CLOSE");
    }

    // Zone 1
    else if (chh == '1')
    {
      lcdprint("MOVING TO", "ZONE 1");
      delay(1500);
      digitalWrite(Relay_Pin,LOW);
      lcdprint("BOX DOOR", "CLOSE"); 
      GoToZone1();
    }

    // Zone 2
    else if (chh == '2')
    {
      lcdprint("MOVING TO", "ZONE 2");
      digitalWrite(Relay_Pin,LOW);
      lcdprint("BOX DOOR", "CLOSE"); 
      GoToZone2();
    }

    // Zone 3
    else if (chh == '3')
    {
      lcdprint("MOVING TO", "ZONE 3");
      digitalWrite(Relay_Pin,LOW);
      lcdprint("BOX DOOR", "CLOSE"); 
      GoToZone3();
    }

    // Zone 4
    else if (chh == '4')
    {
      lcdprint("MOVING TO", "ZONE 4");
      digitalWrite(Relay_Pin,LOW);
      lcdprint("BOX DOOR", "CLOSE"); 
      GoToZone4();
    }

    // Home
    else if (chh == 'h')
    {
      lcdprint("RETURNING", "HOME");
      GoHome();
    }
  }
  }
    
    
    void MotorStopCmd(){
         digitalWrite(LMotor1,LOW);
         digitalWrite(LMotor2,LOW);
         digitalWrite(RMotor1,LOW);
         digitalWrite(RMotor2,LOW);
         delay(500);
    }

    void MotorForwardCmd()
    {
         digitalWrite(LMotor1,LOW);
         digitalWrite(LMotor2,HIGH);
         digitalWrite(RMotor1,LOW);
         digitalWrite(RMotor2,HIGH);
    }
    void MotorReverseCmd(){
         digitalWrite(LMotor1,HIGH);
         digitalWrite(LMotor2,LOW);
         digitalWrite(RMotor1,HIGH);
         digitalWrite(RMotor2,LOW);
    }
    void MotorLeftCmd(){
        digitalWrite(LMotor1,LOW);
        digitalWrite(LMotor2,HIGH);
        digitalWrite(RMotor1,HIGH);
        digitalWrite(RMotor2,LOW);
    }
    void MotorRightCmd(){
        digitalWrite(LMotor1,HIGH);
        digitalWrite(LMotor2,LOW);
        digitalWrite(RMotor1,LOW);
        digitalWrite(RMotor2,HIGH);
    }

    
    
     void MoveForwardTime(int ms)
    {
      MotorForwardCmd();
      delay(ms);
      MotorStopCmd();
    }
    
    void MoveReverseTime(int ms )
    {
      MotorReverseCmd();
      delay(ms);
      MotorStopCmd();
    }
    
    void MoveLeftTime(int ms )
    {
      MotorLeftCmd();
      delay(ms);
      MotorStopCmd();
    }
    
    void MoveRightTime(int ms )
    {
      MotorRightCmd();
      delay(ms);
      MotorStopCmd();
    }


    //Zone 
    void GoToZone1()
    {
      lcdprint("MOVING TO", "ZONE 1");
      MoveForwardTime(7000);
      lcdprint("ZONE 1", "REACHED");
    }
    
    void GoToZone2()
    {
      lcdprint("MOVING TO", "ZONE 2");
      MoveForwardTime(2000 * Mspeed);
      MoveRightTime(r_move_ms);
      MoveForwardTime(1500* Mspeed);
      lcdprint("ZONE 2", "REACHED");
    }
    
    void GoToZone3()
    {
      lcdprint("MOVING TO", "ZONE 3");
      MoveForwardTime(2000* Mspeed);
      MoveLeftTime(l_move_ms);
      MoveForwardTime(1500* Mspeed);
      MoveRightTime(r_move_ms);
      MoveForwardTime(1500* Mspeed);
      lcdprint("ZONE 3", "REACHED");
    }
    
    void GoToZone4()
    {
      lcdprint("MOVING TO", "ZONE 4");
      MoveForwardTime(3500* Mspeed);
      MoveRightTime(r_move_ms);
      MoveForwardTime(2000* Mspeed);
      MoveLeftTime(l_move_ms);
      lcdprint("ZONE 4", "REACHED");
    }
    
    void GoHome()
    {
      lcdprint("RETURNING", "HOME");
      MoveReverseTime(2000* Mspeed);
      lcdprint("HOME", "REACHED");
    }

//Zone End
    void DisplaySpeed()
    {
      SpeedPercent = map(Mspeed, 0, 255, 0, 100);
      lcd.setCursor(0,1);
      lcd.print("Zon_SPD:");
      lcd.print(Mspeed);
      lcd.print("%   ");   // Clear extra characters
      delay(500);
    }



