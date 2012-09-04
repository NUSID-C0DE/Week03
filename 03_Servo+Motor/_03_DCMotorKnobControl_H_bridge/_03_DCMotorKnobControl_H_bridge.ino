/*
  DC motor control
  Control a DC motor through H-Bridge module.
  Change its speed and direction by PWM(analogWrite) control. 
  
  This example code is in the public domain.
 */
 
// an DC motor
// give it a name:
int motorFFPin = 10;
int motorRWDPin = 11;

int midValue = 512;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(motorFFPin, OUTPUT);  
  pinMode(motorRWDPin, OUTPUT);  
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  // read the input on analog pin 0:
  int sensorValue = analogRead(A0) - midValue;
  
  // print out the value you read:
  Serial.println(sensorValue);
  
  int speed;
  speed = map(abs(sensorValue),0,512,0,255);
  
  if(sensorValue > 0){
    analogWrite(motorFFPin, speed);   // turn the LED on (HIGH is the voltage level)
  }else{
    analogWrite(motorRWDPin, speed);   // turn the LED on (HIGH is the voltage level)
  }
  
  
  

   
  

  delay(10);               // wait for a while

}
