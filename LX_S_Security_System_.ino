
#include <SoftwareSerial.h>
const int trigPin = 8;
const int echoPin = 7;
int oneon;
int twoon;
int armed;
int light;
// defines variables
long duration;
int distance;
SoftwareSerial mySerial(A5, A4);// RX, TX
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(4800);
  Serial.println(F("Setting the pinModes..."));
  oneon = 0;
  twoon = 0;
  armed = 0;
  light = 0;
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT_PULLUP);

  digitalWrite(A0, LOW);
  digitalWrite(13, LOW);
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(12, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  digitalWrite(12, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  digitalWrite(12, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(12, HIGH);
  Serial.println(F("Starting your security system..."));
  digitalWrite(10, LOW);
  delay(50);
  digitalWrite(9, HIGH);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds - this helps the sensor get the values
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds - this is an essentail component
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance - speed X time
  distance = duration * 0.034 / 2;
  // Prints the sensor's current state into the serial port.
  Serial.print("Checking the sensor. The sensor code is ");
  Serial.print(distance);
  Serial.print(".");
  delay(100);
  if (distance == 0) {
    Serial.println(" That means the sensor is not working. Please check the sensor.");
    Serial.println(" It can be ignored - we'll boot like normall, but you should get the sensor working.");
    Serial.println(" If you've unplugged the sensor on purpose, don't take note of this message.");
    Serial.println(" But you will not be warned when someone's near. Continuing boot in 5 seconds...");
    delay(5000);
  }
  else {
    Serial.println(" That means the sensor is working fine.");

  }
  Serial.println("Press all buttons in 3 seconds...");
  delay(3000);
  if (digitalRead(6) == LOW && digitalRead(5) == LOW && digitalRead(4) == LOW) {
    Serial.println("Test passed.");
    delay(500);

  }
  else {
    Serial.println("Test was not passed. Did you forget to press the buttons?");
    Serial.println("If you pressed them, they may be broken. Check the wiring and replace buttons.");
  }
  Serial.println("Hold the controler in 3 seconds...");
  delay(3000);
  if (digitalRead(3) == LOW) {
    Serial.println("It works.");

  }
  else {
    Serial.println("it did not work.");

  }
  Serial.println("Testing the alarm...");
  digitalWrite(2, HIGH);
  delay(50);
  digitalWrite(2, LOW);
  delay(50);
  digitalWrite(2, HIGH);
  delay(50);
  digitalWrite(2, LOW);
  delay(50);
  Serial.println("Did you hear those 2 beeps? If so, it's working properly!");
  digitalWrite(A0, HIGH);
  Serial.println("Boot complete. Hold the controller to start monitoring.");
  while (true) {
    if (digitalRead(3) == LOW) {
      mySerial.write('A');
      loop();
    }
  }
}
void loop() {
  mySerial.write('A');
  digitalWrite(2, HIGH);
  delay(50);
  digitalWrite(2, LOW);
  delay(500);
  Serial.println("Press 'F' to see the vorbose output.");
  while (true) {
    if (digitalRead(3) == LOW) {
      if (light == 0) {
  digitalWrite(11, HIGH);
  light = 1;
  digitalWrite(2, HIGH);
  delay(50);
  digitalWrite(2, LOW);
  delay(500);
    }
   else if(light == 1){
      digitalWrite(11,LOW);
      light = 0;
      digitalWrite(2, HIGH);
  delay(50);
  digitalWrite(2, LOW);
  delay(500);
    }
    delay(500);
    }
    if (Serial.read() == 'F') {
      digitalWrite(2, HIGH);
      delay(50);
      digitalWrite(2, LOW);

      VorboseOutputGo();
    }
    if (Serial.read() == '1') {

      digitalWrite(13, LOW);
      digitalWrite(2, HIGH);
      delay(50);
      digitalWrite(2, LOW);
      oneon = 1;
      delay(100);



    }
    if (Serial.read() == '2') {
      digitalWrite(12, LOW);
      digitalWrite(2, HIGH);
      delay(50);
      digitalWrite(2, LOW);
      twoon = 1;
      delay(100);

    }
    if (Serial.read() == '3') {
      digitalWrite(12, HIGH);
      digitalWrite(2, HIGH);
      delay(50);
      digitalWrite(2, LOW);
      twoon = 0;
      delay(100);

    }
    if (Serial.read() == '4') {
      digitalWrite(13, HIGH);
      digitalWrite(2, HIGH);
      delay(50);
      digitalWrite(2, LOW);
      oneon = 0;
      delay(100);
    }
    if (mySerial.read() == 'Z') {
    
      digitalWrite(2, HIGH);
      delay(50);
      digitalWrite(2, LOW);
      oneon = 0;
      delay(100);
    }
    if (Serial.read() == 'A') {
      if (armed == 0) {

        digitalWrite(10, HIGH);
        delay(500);

        ARM();
      }
    }
    if (digitalRead(5) == LOW) {
      digitalWrite(10, HIGH);
      delay(500);

      ARM();
    }




    if (digitalRead(6) == LOW) {
      if (oneon == 0) {
        digitalWrite(13, LOW);
        oneon = 1;
        digitalWrite(2, HIGH);
        delay(50);
        digitalWrite(2, LOW);
        delay(100);
      }
      else if (oneon == 1) {
        digitalWrite(13, HIGH);
        oneon = 0;
        digitalWrite(2, HIGH);
        delay(50);
        digitalWrite(2, LOW);
        delay(100);
      }
    }
    if (digitalRead(4) == LOW) {
      if (twoon == 0) {
        digitalWrite(12, LOW);
        digitalWrite(2, HIGH);
        delay(50);
        digitalWrite(2, LOW);
        twoon = 1;
        delay(100);
      }
      else if (twoon == 1) {
        digitalWrite(12, HIGH);
        digitalWrite(2, HIGH);
        delay(50);
        digitalWrite(2, LOW);
        twoon = 0;
        delay(100);
      }
    }
    delay(10);
  }
}




































void VorboseOutputGo() {
  Serial.println("Verbose logging enabled. Press S to see the human sensor's output.");
  while (true) {
    if (digitalRead(6) == LOW) {
      Serial.println("button one pressed.");
      digitalWrite(2, HIGH);
      delay(50);
      digitalWrite(2, LOW);
      delay(100);
    }
    if (digitalRead(5) == LOW) {
      Serial.println("button two pressed.");
      delay(100);
      digitalWrite(2, HIGH);
      delay(50);
      digitalWrite(2, LOW);
    }
    if (digitalRead(4) == LOW) {
      Serial.println("button three pressed.");
      delay(100);
      digitalWrite(2, HIGH);
      delay(50);
      digitalWrite(2, LOW);
    }
    if (digitalRead(6) == LOW && digitalRead(5) == LOW) {
      Serial.println("button one and two pressed.");
      delay(100);
      digitalWrite(2, HIGH);
      delay(50);
      digitalWrite(2, LOW);
    }
    if (digitalRead(5) == LOW && digitalRead(4) == LOW) {
      Serial.println("button two and three pressed.");
      delay(100);
      digitalWrite(2, HIGH);
      delay(50);
      digitalWrite(2, LOW);
    }
    if (digitalRead(6) == LOW && digitalRead(4) == LOW) {
      Serial.println("button one and three pressed.");
      delay(100);
      digitalWrite(2, HIGH);
      delay(50);
      digitalWrite(2, LOW);
    }
    if (digitalRead(6) == LOW && digitalRead(5) == LOW && digitalRead(4) == LOW) {
      Serial.println("All buttons being pressed.");
      delay(100);
      digitalWrite(2, HIGH);
      delay(50);
      digitalWrite(2, LOW);

    }
    if (digitalRead(3) == LOW) {
      Serial.println("Controller being held/strong light coming into the area");
      delay(100);

    }
    if (digitalRead(6) == LOW && digitalRead(5) == LOW && digitalRead(4) == LOW && digitalRead(3) == LOW ) {
      Serial.println("All controller inputs active.");
      delay(100);
    }
    if (Serial.read() == 'S') {
      digitalWrite(2, HIGH);
      delay(50);
      digitalWrite(2, LOW);
      sensorStart();

    }
    if (Serial.read() == 'X') {
      digitalWrite(2, HIGH);
      delay(50);
      digitalWrite(2, LOW);
      delay(50);
      loop();

    }

  }
}
void sensorStart() {




  while (true) {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds - this helps the sensor get the values
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds - this is an essentail component
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance - speed X time
    distance = duration * 0.034 / 2;
    // Prints the sensor's current state into the serial port.
    delay(200);
    Serial.print("Checking the sensor. The sensor code is ");
    Serial.print(distance);
    Serial.println(".");
    Serial.println("To exit this mode, press X.");
    if (Serial.read() == 'X') {
      digitalWrite(2, HIGH);
      delay(50);
      digitalWrite(2, LOW);
      VorboseOutputGo();

    }
  }
}
void ARM() {
  digitalWrite(2, HIGH);
  delay(200);
  digitalWrite(2, LOW);
  delay(50);
digitalWrite(9, LOW);
  Serial.println("Armed. Ready for action.");
  while (true) {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds - this helps the sensor get the values
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds - this is an essentail component
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance - speed X time
    distance = duration * 0.034 / 2;
    delay(500);
    
    Serial.println(distance);

    if (distance <= 50) {
      Serial.print("!");
      digitalWrite(2, HIGH);
      digitalWrite(10, LOW);
      delay(50);
      digitalWrite(2, LOW);
      digitalWrite(10, HIGH);
      delay(500);
    }
    if (digitalRead(5) == LOW) {
      armed = 0;
      digitalWrite(10, LOW);
      digitalWrite(2, HIGH);
      delay(100);
      digitalWrite(2, LOW);
      digitalWrite(9, HIGH);
      loop();
    }
    if (digitalRead(A3) == HIGH) {
      while (true) {
        digitalWrite(13, LOW);
        digitalWrite(12, LOW);
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
        digitalWrite(9, LOW);
        digitalWrite(8, LOW);

        digitalWrite(2, HIGH);
        if (digitalRead(6) == LOW && digitalRead(5) == LOW && digitalRead(4) == LOW) {
          digitalWrite(2, LOW);
          digitalWrite(9, HIGH);
          armed = 0;
          loop();
        }
      }
    }
  }


}
