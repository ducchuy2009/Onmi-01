
#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
char t;
int pinA1 = 11;    
int pinA2 = 10;    
int pinB1 = 6;    
int pinB2 = 5;  

void setup() {
BTserial.begin(9600);

pinMode (pinA1, OUTPUT);
pinMode (pinA2, OUTPUT);  
  
pinMode (pinB1, OUTPUT);
pinMode (pinB2, OUTPUT);  
}

void loop() {
  
if (BTserial.available())
    {  
        t = BTserial.read();
    }
if (t == 'F'){
  forward(150);

}
else if (t == 'B'){
  reverse(150);

}
else if (t == 'L'){
  left(150);
}
else if (t == 'R'){
  right(150);
}
else if (t == 'A'){
  stopcar();
}


delay(100);
}

void forward(int s){
  digitalWrite (pinA1, LOW);
  digitalWrite (pinA2, LOW);
  digitalWrite (pinB1, LOW);
  digitalWrite (pinB2, LOW);
digitalWrite (pinA1, HIGH);
digitalWrite (pinB1, HIGH);
analogWrite (pinA1, s);
analogWrite (pinB1, s);

}

void reverse(int s){
  digitalWrite (pinA1, LOW);
  digitalWrite (pinA2, LOW);
  digitalWrite (pinB1, LOW);
  digitalWrite (pinB2, LOW);
  digitalWrite (pinA2, HIGH);
  digitalWrite (pinB2, HIGH);
  analogWrite (pinA2, s); 
  analogWrite (pinB2, s);  
 
}

void stopcar(){
  digitalWrite (pinA1, LOW);
  digitalWrite (pinA2, LOW);
  digitalWrite (pinB1, LOW);
  digitalWrite (pinB2, LOW);
}

void right(int s){ 
  digitalWrite (pinA2, LOW);
  digitalWrite (pinB1, LOW);
  digitalWrite (pinB2, LOW);
  analogWrite (pinA1, s);
  analogWrite (pinB1, 0);
  delay(50);
    }

void left(int s){
  digitalWrite (pinA1, LOW);
  digitalWrite (pinA2, LOW);
  digitalWrite (pinB2, LOW);
  analogWrite (pinB1, s);
  analogWrite (pinA1, 0);
  delay(50);
}
