int PIN_ROW_FET = 9;
int PIN_COLUMN_FET = 10;

void setup() {
  Serial.begin(9600);
  Serial.println("Hello world!");
  pinMode(PIN_ROW_FET, OUTPUT);
  pinMode(PIN_COLUMN_FET, OUTPUT);
}

void loop() {
  Serial.println("On");
  digitalWrite(PIN_ROW_FET, LOW);
  digitalWrite(PIN_COLUMN_FET, HIGH);
  delay(5000);

  Serial.println("Off");
  digitalWrite(PIN_ROW_FET, LOW);
  digitalWrite(PIN_COLUMN_FET, LOW);
  delay(5000);

  // int a = analogRead(1);
  // Serial.print(a);
  // if (a < 338)
    // Serial.println(" I");
  // delay(200);
}