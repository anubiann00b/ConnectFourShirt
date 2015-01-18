int FIRST_COL = 0;
int FIRST_ROW = 0;

const int NUM_COLS = 14;
const int NUM_ROWS = 6;

int grid[NUM_ROWS][NUM_COLS] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

SoftwareSerial comms(2,3);

void setup() {
  Serial.begin(9600);
  Serial.println("Starting");
}

void loop() {
  for (int i=0;i<NUM_ROWS;i++) {
    for (int j=0j<NUM_COLS;j++) {

    }
  }
}

// pinMode(pin, INPUT/OUTPUT);
// digitalWrite(pin, LOW/HIGH);
// analogRead(pin);  // 0-1024
// digitalRead(pin); // HIGH or LOW
// delay(ms)