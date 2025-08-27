const int sensor = A1;    
const int ledgreen = 4, ledred =7, ledyellow =3 , buzzer = 5;

int prev = 0;

void setup() {
  pinMode(ledgreen, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(ledyellow, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Average 10 readings
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(sensor);
    delay(5);
  }
  int value = sum / 10;

  // Check movement
  if (value > prev + 5) {          // Ascending
    digitalWrite(ledgreen, HIGH);
    digitalWrite(ledred, LOW);
    digitalWrite(ledyellow, LOW);
  } 
  else if (value < prev - 5) {     // Descending
    digitalWrite(ledgreen, LOW);
    digitalWrite(ledred, HIGH);
    digitalWrite(ledyellow, LOW);
  } 
  else {                           // Stable
    digitalWrite(ledgreen, LOW);
    digitalWrite(ledred, LOW);
    digitalWrite(ledyellow, HIGH);
  }

  // Buzzer at peak
  if (value > 600) tone(buzzer, 1000);
  else noTone(buzzer);

  Serial.println(value);  // Debug
  prev = value;
  delay(200);
}