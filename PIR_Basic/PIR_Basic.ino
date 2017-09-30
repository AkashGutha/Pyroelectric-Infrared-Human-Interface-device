// pin settings
#define PIR_PIN 7
#define LED_PIN 13

// program and env settings
#define CALIBRATION_TIME 30

// public varibales
float reading = 0;

void setup() {
  // setup serial monitor for sending back data.
  Serial.begin(9600);
  Serial.println("Heating up the transistors.....");

  // setup PIR pin for input adn LED pin for output
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(PIR_PIN, LOW);

  //give the sensor some time to calibrate
  Serial.print("calibrating my neurons");
  for (int i = 0; i < CALIBRATION_TIME; i++) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Bring up the Motion Ninjas....");
  delay(50);
}


void loop() {

  reading = digitalRead(PIR_PIN);

  if (reading == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  Serial.println(reading);
}
