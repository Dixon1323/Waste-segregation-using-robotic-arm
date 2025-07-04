#include <Servo.h>

Servo bottom;
Servo shoulder;
Servo elbow;
Servo hand;
Servo gripper;

int pos,dely=800;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,HIGH);
  bottom.attach(3);
  shoulder.attach(5);
  elbow.attach(6);
  hand.attach(9);
  gripper.attach(10);
  initial();
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
    if (Serial.available())
    {
        String a = Serial.readString();
        Serial.print("Received Value: ");
        Serial.println(a);
        int b = a.toInt();
        if(b==1){
          digitalWrite(LED_BUILTIN,HIGH);
          delay(200);
          digitalWrite(LED_BUILTIN,LOW);
          pickup();
          delay(2000);
          degrade();

        }
        else if(b==2){
          digitalWrite(LED_BUILTIN,HIGH);
          delay(200);
          digitalWrite(LED_BUILTIN,LOW);
          delay(200);
          digitalWrite(LED_BUILTIN,HIGH);
          delay(200);
          digitalWrite(LED_BUILTIN,LOW);
          pickup();
          delay(2000);
          no_degrade();

        }
    }
}


void initial() {
  hand.detach();
  bottom.detach();
  shoulder.write(90);
  delay(2000);
  gripper.write(170);
  delay(2000);
  elbow.write(90);
  delay(2000);
  hand.attach(9);
  hand.write(180);
  delay(2000);
  bottom.attach(3);
  bottom.write(90);
  delay(2000);
}

void pickup() {
  for (pos = 90; pos >= 0; pos--) {
    bottom.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 90; pos >= 50; pos--) {
    shoulder.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 90; pos >= 50; pos--) {
    elbow.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 50; pos >= 25; pos--) {
    shoulder.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 180; pos >= 160; pos--) {
    hand.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 180; pos >= 90; pos--) {
    gripper.write(pos);
    delay(15);
  }
  delay(dely);
}

void degrade() {
  for (pos = 18; pos <= 70; pos++) {
    shoulder.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 50; pos <= 90; pos++) {
    elbow.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 160; pos >= 140; pos--) {
    hand.write(pos);
    delay(15);
  }
  delay(dely);

  for (pos = 0; pos <= 180; pos++) {
    bottom.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 70; pos >= 50; pos--) {
    shoulder.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 90; pos >= 50; pos--) {
    elbow.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 50; pos >= 30; pos--) {
    shoulder.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 90; pos <= 160; pos++) {
    gripper.write(pos);
    delay(15);
  }
  delay(dely);
  delay(5000);
  reset(180);
}

void no_degrade() {
  for (pos = 18; pos <= 70; pos++) {
    shoulder.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 50; pos <= 90; pos++) {
    elbow.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 160; pos >= 140; pos--) {
    hand.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 0; pos <= 160; pos++) {
    bottom.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 70; pos >= 50; pos--) {
    shoulder.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 90; pos >= 50; pos--) {
    elbow.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 50; pos >= 25; pos--) {
    shoulder.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 90; pos <= 180; pos++) {
    gripper.write(pos);
    delay(15);
  }
  delay(dely);
  delay(5000);
  reset(160);
}

void reset(int angle) {

  for (pos = 25; pos <= 90; pos++) {
    shoulder.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 50; pos <= 90; pos++) {
    elbow.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = 140; pos <= 160; pos++) {
    hand.write(pos);
    delay(15);
  }
  delay(dely);
  for (pos = angle; pos >= 90; pos--) {
    bottom.write(pos);
    delay(15);
  }
}
