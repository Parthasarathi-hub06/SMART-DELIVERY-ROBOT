// ************** Main code , to run repeatedly  *********************************************** 
void loop() {
Serial_bt_Read();
Serial_bt_Write(String("100"), String("200"), String("300"), String("400"), String("500"), String("600"));
sendBluetoothData();
distance = readPing();
        lcd.setCursor(0,0);
        lcd.print(" US = ");
        lcd.print(distance);
        lcd.print("  ");


        if(distance <= 25){
            MotorStopCmd();
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("-OBJECT DETECT -   ");
            lcd.setCursor(0,1);
            lcd.print("                    ");
            delay(500);
            lcd.clear();
            
        }else{
            DCMotorCondition();
        }

}
// ************** Main code END  *********************************************** 