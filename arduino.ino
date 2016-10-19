#include <string.h>
 
char unitID_in[10];
char command_in[10];
char data_in[100];
String message;
char incomingChar;

float Kturn = 2.6;
    
int LF= 13; // player 1 left forward 
int LB= 12; // player 1 left back
int RF= 11; // player 1 right forward
int RB= 10; // player 1 right back
int TL= 9; // player 1 turret left
int TR= 8; // player 1 turret right
int FR= 7; // player 1 fire
int PW= 6; // player 1 power

int LF2= 5; // player 2 left forward
int LB2= 4; // player 2 left back
int RF2= 3; // player 2 right forward
int RB2= 2; // player 2 right back
int TL2= 14; // player 2 turret left
int TR2= 15; // player 2 turret right
int FR2= 16; // player 2 fire
int PW2= 17; // player 2 power


int motor1 = 0;
int motor2 = 0;
int motor_data = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(TL, OUTPUT);
  pinMode(TR, OUTPUT);
  pinMode(FR, OUTPUT);
  pinMode(PW, OUTPUT);
digitalWrite(LF, LOW); // PNP
digitalWrite(LB, HIGH); // NPN
digitalWrite(RF, LOW);
digitalWrite(RB, HIGH);
digitalWrite(TL, LOW);
digitalWrite(TR, HIGH);
digitalWrite(FR, LOW);
digitalWrite(PW, HIGH);

  pinMode(LF2, OUTPUT);
  pinMode(LB2, OUTPUT);
  pinMode(RF2, OUTPUT);
  pinMode(RB2, OUTPUT);
  pinMode(TL2, OUTPUT);
  pinMode(TR2, OUTPUT);
  pinMode(FR2, OUTPUT);
  pinMode(PW2, OUTPUT);
digitalWrite(LF2, LOW);
digitalWrite(LB2, HIGH);
digitalWrite(RF2, LOW);
digitalWrite(RB2, HIGH);
digitalWrite(TL2, LOW);
digitalWrite(TR2, HIGH);
digitalWrite(FR2, LOW);
digitalWrite(PW2, HIGH);

Serial.begin(9600);
}

void Move(int value) {
  if (value > 0)
  {
  digitalWrite(LF, HIGH);
  digitalWrite(RF, HIGH);  
  delay(value * 64);
  digitalWrite(LF, LOW);
  digitalWrite(RF, LOW);
  } 
   if (value < 0)
  {
  digitalWrite(LB, LOW);
  digitalWrite(RB, LOW);  
  delay(-1 * value * 64);
  digitalWrite(LB, HIGH);
  digitalWrite(RB, HIGH);
  }  
}

void Turn(int value) {
  if (value > 0)
  {
  digitalWrite(LF, HIGH);
  digitalWrite(RB, LOW);  
  delay(value * Kturn);
  digitalWrite(LF, LOW);
  digitalWrite(RB, HIGH);
  } 
   if (value < 0)
  {
  digitalWrite(LB, LOW);
  digitalWrite(RF, HIGH);  
  delay(-1 * value * Kturn);
  digitalWrite(LB, HIGH);
  digitalWrite(RF, LOW);
  }  
}

void Rotate(int value) {
  if (value < 0)
  {
  digitalWrite(TL, HIGH);  
  delay(-1 * value * 16);
  digitalWrite(TL, LOW);
  } 
   if (value > 0)
  {
  digitalWrite(TR, LOW);  
  delay(value * 16);
  digitalWrite(TR, HIGH);
  }  
}

void Fire() {
  digitalWrite(FR, HIGH);  
  delay(500);
  digitalWrite(FR, LOW); 
}

void Power() {
  digitalWrite(PW, LOW);  
  delay(500);
  digitalWrite(PW, HIGH); 
}

void SilentPower() {
  digitalWrite(FR, HIGH);
  delay(250);
  digitalWrite(PW, LOW);  
  delay(500);
  digitalWrite(PW, HIGH);
  delay(250);
  digitalWrite(FR, LOW);
}

void Motor(int valueL, int valueR) {
  if (valueL > 0)
  {
  digitalWrite(LF, HIGH);  
  }
  
  if (valueL < 0)
  {
  digitalWrite(LB, LOW);
  }

 if (valueR > 0)
  {
  digitalWrite(RF, HIGH);  
  }
  
  if (valueR < 0)
  {
  digitalWrite(RB, LOW);
  }

 if (valueL == 0)
  {
  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);  
  }
  
  if (valueR == 0)
  {
  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);  
  }
  
}








void Move2(int value) {
  if (value > 0)
  {
  digitalWrite(LF2, HIGH);
  digitalWrite(RF2, HIGH);  
  delay(value * 64);
  digitalWrite(LF2, LOW);
  digitalWrite(RF2, LOW);
  } 
   if (value < 0)
  {
  digitalWrite(LB2, LOW);
  digitalWrite(RB2, LOW);  
  delay(-1 * value * 64);
  digitalWrite(LB2, HIGH);
  digitalWrite(RB2, HIGH);
  }  
}

void Turn2(int value) {
  if (value > 0)
  {
  digitalWrite(LF2, HIGH);
  digitalWrite(RB2, LOW);  
  delay(value * Kturn);
  digitalWrite(LF2, LOW);
  digitalWrite(RB2, HIGH);
  } 
   if (value < 0)
  {
  digitalWrite(LB2, LOW);
  digitalWrite(RF2, HIGH);  
  delay(-1 * value * Kturn);
  digitalWrite(LB2, HIGH);
  digitalWrite(RF2, LOW);
  }  
}

void Rotate2(int value) {
  if (value < 0)
  {
  digitalWrite(TL2, HIGH);  
  delay(-1 * value * 16);
  digitalWrite(TL2, LOW);
  } 
   if (value > 0)
  {
  digitalWrite(TR2, LOW);  
  delay(value * 16);
  digitalWrite(TR2, HIGH);
  }  
}

void Fire2() {
  digitalWrite(FR2, HIGH);  
  delay(500);
  digitalWrite(FR2, LOW); 
}

void Power2() {
  digitalWrite(PW2, LOW);  
  delay(500);
  digitalWrite(PW2, HIGH); 
}

void SilentPower2() {
  digitalWrite(FR2, HIGH);
  delay(250);
  digitalWrite(PW2, LOW);  
  delay(500);
  digitalWrite(PW2, HIGH);
  delay(250);
  digitalWrite(FR2, LOW);
}

void Motor2(int valueL, int valueR) {
  if (valueL > 0)
  {
  digitalWrite(LF2, HIGH);  
  }
  
  if (valueL < 0)
  {
  digitalWrite(LB2, LOW);
  }

 if (valueR > 0)
  {
  digitalWrite(RF2, HIGH);  
  }
  
  if (valueR < 0)
  {
  digitalWrite(RB2, LOW);
  }

 if (valueL == 0)
  {
  digitalWrite(LF2, LOW);
  digitalWrite(LB2, HIGH);  
  }
  
  if (valueR == 0)
  {
  digitalWrite(RF2, LOW);
  digitalWrite(RB2, HIGH);  
  }
  
}




// the loop routine runs over and over again forever:
void loop() {
  
  int i=0;
  char buffer[100];
 
//если есть данные - читаем
  if(Serial.available()){
     delay(100);
      
     //загоняем прочитанное в буфер
     while( Serial.available() && i< 99) {
        buffer[i++] = Serial.read();
     }
     //закрываем массив
     buffer[i++]='\0';
  }
 
//если буфер наполнен
  if(i>0){  
     
    //разбераем его на части отделенные запятой
    sscanf(buffer, "%[^','],%[^','],%s", &unitID_in, &command_in, &data_in);
     
  }
   
//Исполнительная часть
//Проверяем какому устройству пришли данные     
//пример выполнения команды устройством 001
     if ((String)unitID_in == "001"){

      Serial.print("unit: ");
      Serial.print(unitID_in);
      Serial.print("\n");
      Serial.print("command: ");
      Serial.print(command_in);
      Serial.print("\n");
      Serial.print("data: ");
      Serial.print(data_in);      
      Serial.print("\n");

      if ((String)command_in == "M"){
          Move(int(atof(data_in)));}

      if ((String)command_in == "T"){
          Turn(int(atof(data_in)));}
          
      if ((String)command_in == "R"){
          Rotate(int(atof(data_in)));}

      if ((String)command_in == "F"){
          Fire();}          

      if ((String)command_in == "P"){
          Power();}

      if ((String)command_in == "S"){
          SilentPower();}          

      if ((String)command_in == "m"){
        
          motor_data = int(atof(data_in));
        
          if (motor_data < 100) {
            motor1 = 0;  
          }
          if (motor_data >= 100) {
            motor1 = 1;  
          }         
          if (motor_data >= 200) {
            motor1 = -1;  
          }
         
         motor_data = motor_data%100;

          if (motor_data < 10) {
            motor2 = 0;  
          }
          if (motor_data >= 10) {
            motor2 = 1;  
          }         
          if (motor_data >= 20) {
            motor2 = -1;  
          }          
      
      Motor(motor1,motor2);
          
      motor1 = 0;
      motor2 = 0;
      motor_data = 0;          
      }

      unitID_in [0] = '\0'; 
      command_in [0] = '\0';
      data_in [0] = '\0';          
    }
  
  
  
  
  //пример выполнения команды устройством 002
     if ((String)unitID_in == "002"){

      Serial.print("unit: ");
      Serial.print(unitID_in);
      Serial.print("\n");
      Serial.print("command: ");
      Serial.print(command_in);
      Serial.print("\n");
      Serial.print("data: ");
      Serial.print(data_in);      
      Serial.print("\n");

      if ((String)command_in == "M"){
          Move2(int(atof(data_in)));}

      if ((String)command_in == "T"){
          Turn2(int(atof(data_in)));}
          
      if ((String)command_in == "R"){
          Rotate2(int(atof(data_in)));}

      if ((String)command_in == "F"){
          Fire2();}          

      if ((String)command_in == "P"){
          Power2();}

      if ((String)command_in == "S"){
          SilentPower2();}          

      if ((String)command_in == "m"){
        
          motor_data = int(atof(data_in));
        
          if (motor_data < 100) {
            motor1 = 0;  
          }
          if (motor_data >= 100) {
            motor1 = 1;  
          }         
          if (motor_data >= 200) {
            motor1 = -1;  
          }
         
         motor_data = motor_data%100;

          if (motor_data < 10) {
            motor2 = 0;  
          }
          if (motor_data >= 10) {
            motor2 = 1;  
          }         
          if (motor_data >= 20) {
            motor2 = -1;  
          }          
      
      Motor2(motor1,motor2);
          
      motor1 = 0;
      motor2 = 0;
      motor_data = 0;          
      }

      unitID_in [0] = '\0'; 
      command_in [0] = '\0';
      data_in [0] = '\0';          
    }
  
  
  
}
