int PIN_ROW_FET = 8;
int PIN_COLUMN_FET = 8;

void setup() {
  Serial.begin(9600);
  Serial.println("Hello world!");
  pinMode(PIN_ROW_FET, OUTPUT);
  pinMode(PIN_COLUMN_FET, OUTPUT);
}

void loop() {
  Serial.println("Row and Column");
  digitalWrite(PIN_ROW_FET, LOW);
  digitalWrite(PIN_COLUMN_FET, LOW);
  delay(10000);

  Serial.println("Column");
  digitalWrite(PIN_ROW_FET, HIGH);
  digitalWrite(PIN_COLUMN_FET, LOW);
  delay(5000);

  Serial.println("Row");
  digitalWrite(PIN_ROW_FET, LOW);
  digitalWrite(PIN_COLUMN_FET, HIGH);
  delay(5000);

  Serial.println("None");
  digitalWrite(PIN_ROW_FET, HIGH);
  digitalWrite(PIN_COLUMN_FET, HIGH);
  delay(5000);

  // int a = analogRead(1);
  // Serial.print(a);
  // if (a < 338)
    // Serial.println(" I");
  // delay(200);
}