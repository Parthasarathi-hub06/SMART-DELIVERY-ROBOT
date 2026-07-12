// ************** Pin Configuration *********************************************** 

char Serial_bt_Chh;

void Serial_bt_Read();
//void Serial_bt_Write();
unsigned long previousMillis = 0;
const long Send_interval = 500; // 1 second gap
int sendIndex = 0;
String values[6];

int bt_Sensor_Count = 0;
#define TRIG_PIN  A0
#define ECHO_PIN  A1
#define MAX_DISTANCE 200 
#define MAX_SPEED 190 // sets speed of DC  motors
#define MAX_SPEED_OFFSET 20

int distance = 100;
String dis = "100";

int r_move_ms = 3200;
int l_move_ms = 3200;
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

/* Motor Pin Controller*/
int LMotor1 =8;
int LMotor2 =9;
int RMotor1 =10;
int RMotor2 =11;

void DCMotorCondition();

void GoToZone1();
void GoToZone2();
void GoToZone3();
void GoToZone4();
void GoHome();

void MotorStopCmd();
void MoveForwardTime(int ms);
void MoveReverseTime(int ms);
void MoveLeftTime(int ms);
void MoveRightTime(int ms);

char chh;

int Mspeed = 1;          // Initial speed (0–255)
int SpeedPercent = 0;      // Speed in percentage

int Relay_Pin = 5;

