#define ldrpinA A0
#define ldrpinB A1
#define distBTWlaser 25  // distance between 2 lasers in cm
int laserA = 4;
int laserB = 5;
unsigned long currentMillis = 0;
unsigned long elapsedTime = 0;
double Speed = 0.0;
void setup() {
  // put your setup code here, to run once:
  //pinMode (ldrA, INPUT); //change variable to A0, A1, A2 etc if sensor connected on analog pin
  //pinMode (ldrB, INPUT); //change variable to A0, A1, A2 etc if sensor connected on analog pin
  pinMode (laserA, OUTPUT);
  pinMode (laserB, OUTPUT);
  Serial.begin(9600); //for debugging and printing result
}

void loop() {
  // first test your LDR to find the thresh hold values, let me know if you need the threshhold code
  digitalWrite (laserA, HIGH);
  digitalWrite (laserB, HIGH);
  int ldrA = analogRead(ldrpinA);
  int ldrB = analogRead(ldrpinB);
  if (ldrA < 500){
    currentMillis = millis();
  }
  if (ldrB < 500){
    elapsedTime = millis()-currentMillis;
  }
  Speed = (distBTWlaser/100)/elapsedTime;
  Serial.print("Speed of passing object is: ");
  Serial.println(Speed);
}
