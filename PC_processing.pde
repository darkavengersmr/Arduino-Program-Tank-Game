import processing.serial.*;

Serial myPort;

int tank = 1;
 
void setup() {

  println(Serial.list());

  myPort = new Serial(this, Serial.list()[1], 9600);
      
  delay (2000);
}

void Move(int value) {
  println("Tank:"+tank+" Move:"+value);  
  myPort.write("00"+tank+",M,"+value);
  if (value > 0) delay(value*64 + 1000);
  else delay(-1 * value*4 + 1000);
  delay(500);
}

void Turn(int value) {
  println("Tank:"+tank+" Turn:"+value);  
  myPort.write("00"+tank+",T,"+value);
  if (value > 0) delay(value*4 + 1000);
  else delay(-1 * value*4 + 1000);
  delay(500);
} 

void Wait(int value) {
  println("Tank:"+tank+" Wait:"+value); 
  delay(value*1000);
  delay(500);
} 

void Rotate(int value) {
  println("Tank:"+tank+" Rotate:"+value);   
  myPort.write("00"+tank+",R,"+value);
  if (value > 0) delay(value*16 + 1000);
  else delay(-1 * value*16 + 1000);
  delay(500);
}

void Fire() {
  println("Tank:"+tank+" Fire");  
  myPort.write("00"+tank+",F,001");
  //delay(1000);
  delay(500);
}

void Power() {
  println("Tank:"+tank+" Power");  
  myPort.write("00"+tank+",P,001");
  delay(1000);
}

void SilentPower() {
  println("Tank:"+tank+" SilentPower");  
  myPort.write("00"+tank+",S,001");  
  delay(1000);
}

void Motor(int motor1, int motor2) {
  int value = 0;
  if (motor1 > 0) value = value + 100;
  if (motor1 < 0) value = value + 200;
  if (motor2 > 0) value = value + 10;
  if (motor2 < 0) value = value + 20;
  println("Tank:"+tank+" Motor:"+motor1+","+motor2+" Serial:"+value,10,100); 
  myPort.write("00"+tank+",m,"+value);
}

void FireX(int a) 
{
  
    for(int i = 0; i <= a; i++) 
    {
     Fire();
    }

  
}


void draw() {
           
  /* Commands:
  Move(cm); 
  Turn(grad);
  Rotate(grad);
  Fire();
  Power();
  SilentPower();
  Wait(sec);
  Motor(Left,Right);
  */
 
  tank = 2;
  
   Move(12);
   Rotate(-90);
  
 tank = 1;
 
  Power();

   Wait(1);
   Move(7);
   Rotate(-90);
   Wait(1);
   Fire();
   Wait(1);
   Fire();
   
   tank = 2; 
   Fire();
   Wait(1);
   Fire();
   
 tank = 1;
  Power(); 
  
  
  
  
  exit();  
}
