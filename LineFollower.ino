//our L298N control pins
const int LeftMotorForward = 5;         // GOES TO IN2 OF DRIVER
const int LeftMotorBackward = 4;        // GOES TO IN1 OF DRIVER  
const int RightMotorForward = 3;        // GOES TO IN4 OF DRIVER
const int RightMotorBackward = 2;       // GOES TO IN3 OF DRIVER

//sensor pins
int LEFTsensor = 12;                  //LEFT  IR OUTPUT
int MIDDLEsensor = 11;                //MID   IR OUTPUT
int RIGHTsensor = 10;                 //RIGHT IR OUTPUT

boolean goingforward = false;



void setup(){

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(LEFTsensor, INPUT);
  pinMode(MIDDLEsensor, INPUT);
  pinMode(RIGHTsensor, INPUT);

}

void loop()
{
int Lsensor = digitalRead(12);
int Msensor = digitalRead(11);
int Rsensor = digitalRead(10);

//FORWARD
if (Lsensor==false && Msensor==true && Rsensor==false && goingforward == false){
forward();
goingforward==true;
}


//RIGHT 
else if(Lsensor==false && Msensor==false && Rsensor==true)
turn_slow_right();

else if(Lsensor==false && Msensor==true && Rsensor==true)
turn_fast_right();

//LEFT
else if(Lsensor==true && Msensor==false && Rsensor==false)
turn_slow_left();
else if(Lsensor==true && Msensor==true && Rsensor==false)
turn_fast_left();


//STOP
else if(Lsensor==true && Msensor==true && Rsensor==true)
stopit();
else if(Lsensor==false && Msensor==false && Rsensor==false)
stopit();
else if(Lsensor==true && Msensor==false && Rsensor==true)
stopit();

delay(5);
}






//**************************************
void stopit()
{
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  
}
void forward()
{
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void turn_slow_left()
{
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  goingforward==false;
 }

void turn_fast_left()
{
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  goingforward==false;
}

void turn_slow_right()
{
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  goingforward==false;
}
void turn_fast_right()
{
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward,HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  goingforward==false;
}
