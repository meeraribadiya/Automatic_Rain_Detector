#include <Servo.h>

Servo myservo;

// Pin setup
const int rainPin = 2;
const int buzzer = 8;
const int led1 = 3;
const int led2 = 4;
const int led3 = 5;

void setup() {
  pinMode(rainPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  myservo.attach(9);
  myservo.write(180);  // start at 180°  
}

void loop() {
  int rain = digitalRead(rainPin);

  if (rain == LOW) { // LOW = rain detected (for most sensors)
    // Servo move
    myservo.write(90);
    delay(1000);

    // Buzzer "tu tu"
    for (int i = 0; i < 2; i++) {
      digitalWrite(buzzer, HIGH);
      delay(200);
      digitalWrite(buzzer, LOW);
      delay(200);
    }

    // LEDs ON one by one
    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led3, HIGH);
    delay(500);
  } else {
    // Reset state if no rain
    myservo.write(180);
    digitalWrite(buzzer, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
}