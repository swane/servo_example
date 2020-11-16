void setup() {
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  float a;
  float b;
  float desired_angle;
  float actual_angle;
  float error;
  float motor;
  float setpoint;
  a=analogRead(A1);
  desired_angle=map(a,0,1023,0,270);
  
  b=analogRead(A2);
  actual_angle=map(b,0,1023,0,270);
  error=4*(desired_angle-actual_angle);
  Serial.print(desired_angle);
  Serial.print(" , ");
  Serial.print(actual_angle);
  
  Serial.print(" , ");
  Serial.println(error);
  if (error>0)
  {
    digitalWrite(5,LOW);
    analogWrite(6,error);
  }
  if (error<0)
  {
    digitalWrite(6,LOW);
    analogWrite(5,-1*error);
  }
}
