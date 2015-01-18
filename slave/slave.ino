#include "SoftwareSerial.h"
#include "Event.h"
#include "Timer.h"

int FIRST_COL = 0;
int FIRST_ROW = 0;

int NUM_COLS = 14;
int NUM_ROWS = 6;

int NUM_INPUTS = 1;
int FIRST_INPUT = 6;
int FIRST_INPUT_COL = 6;

SoftwareSerial comms(2,3);
Timer timer;

int cols[NUM_COLS] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void setup() {
  Serial.begin(9600);
  comms.begin(9600);

  Serial.println("Waiting for Master");
  while (comms.read() == -1);
  Serial.println("Starting Slave");

  timer.every(20, pollInputs);
  timer.every(10, updateGrid);
}

void loop() {
  timer.update();
  char c = comms.read();
  if (c != -1) {
    switch (c) {
        case 'c':
          for (int i=0;i<NUM_COLS;i++)
            cols[i] = comms.read();
        default:
          break;
    }
  }
}

void updateGrid() {
  for (int i=0;i<NUM_COLS;i++) {
    if (cols[i] == 0) {
      pinMode(currentCol+FIRST_COL, INPUT);
    } else {
      pinMode(currentCol+FIRST_COL, OUTPUT);
      digitalWrite(currentCol+FIRST_COL, HIGH);
    }
  }
}

void pollInputs() {
  for (int i=0;i<NUM_INPUTS;i++) {
    int a = analogRead(i+FIRST_INPUT);
    if (a < 338)
      handleInput(i+FIRST_INPUT_COL);
  }
}

void handleInput(int col) {
  comms.write('i');
  comms.write(col);
}

// pinMode(pin, INPUT/OUTPUT);
// digitalWrite(pin, LOW/HIGH);
// analogRead(pin);  // 0-1024
// digitalRead(pin); // HIGH or LOW
// delay(ms)