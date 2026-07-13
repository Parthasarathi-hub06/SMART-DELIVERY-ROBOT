// ************** Initial Setup Code *********************************************** 
void setup() { 
Serial.begin(9600);
Serial.println( "Initializing Bluetooth Communication" );

lcd.begin();
      lcd.backlight();
      lcd.print("LCD Init..!");
      delay(1000);
      // Scroll message across first line
        for (int i = 0; i < message.length() - 15; i++) {
          lcd.setCursor(0, 0);
          lcd.print(message.substring(i, i + 16));  // Display 16 characters at a time
          delay(Scrolling_Speed);  // Scrolling_Speed
        }

  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  
        delay(1000);
        lcd.clear();
        lcdprint("Initilized","Sucessfully");
        // lcdprint("","");

  Serial.begin(9600);
  pinMode(LMotor1,OUTPUT);
  digitalWrite(LMotor1,LOW);
  pinMode(LMotor2,OUTPUT);
  digitalWrite(LMotor2,LOW);
  pinMode(RMotor1,OUTPUT);
  digitalWrite(RMotor1,LOW);
  pinMode(RMotor2,OUTPUT);
  digitalWrite(RMotor2,LOW);
  MotorStopCmd();
  delay(200);
MoveRightTime(r_move_ms);
delay(500);
MoveLeftTime(l_move_ms);

// Relay_Pin
pinMode (Relay_Pin,OUTPUT);
digitalWrite(Relay_Pin,HIGH);
//digitalWrite(Relay_Pin,LOW);
}


