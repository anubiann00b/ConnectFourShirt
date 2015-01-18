#include "SoftwareSerial.h"
#include "Event.h"
#include "Timer.h"

int NUM_COLS = 2;
int NUM_ROWS = 6;

int ROWS_PIN_START = 0;
int COLS_PIN_START = 6;

int NUM_INPUTS = 2;

int BLUE_PLAYER = 1;
int GREEN_PLAYER = 2;

int grid[6][4] = {
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}
};

Timer timer;

int currentRow = 0;
int currentPlayer = BLUE_PLAYER;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting Master");
  timer.every(20, pollInputs);
  timer.every(10, updateGrid);
}

void loop() {
  timer.update();
}

void updateGrid() {
  pinMode(currentRow+ROWS_PIN_START, INPUT);

  currentRow++;
  if (currentRow > NUM_ROWS)
    currentRow = 0;

  pinMode(currentRow+ROWS_PIN_START, OUTPUT);
  digitalWrite(currentRow+ROWS_PIN_START, HIGH);

  for (int i=0;i<NUM_COLS;i++) {
    switch (grid[currentRow][i]) {
      case 0:
        pinMode(COLS_PIN_START+i, INPUT);
        pinMode(COLS_PIN_START+i+1, INPUT);
        break;
      case BLUE_PLAYER:
        pinMode(COLS_PIN_START+i, OUTPUT);
        pinMode(COLS_PIN_START+i+1, INPUT);
        break;
      case GREEN_PLAYER:
        pinMode(COLS_PIN_START+i, INPUT);
        pinMode(COLS_PIN_START+i+1, OUTPUT);
        break;
      default:
        break;
    }
  }
}

void pollInputs() {
  for (int i=0;i<NUM_INPUTS;i++) {
    int a = analogRead(i);
    if (a < 338)
      handleInput(i);
  }
}

void handleInput(int col) {
  for (int i=NUM_ROWS;i>0;i--) {
    if (grid[i][col] != 0)
      continue;
    grid[i][col] = currentPlayer;
    if (currentPlayer == GREEN_PLAYER)
      currentPlayer = BLUE_PLAYER;
    else
      currentPlayer = GREEN_PLAYER;
  }
}

// pinMode(pin, INPUT/OUTPUT);
// digitalWrite(pin, LOW/HIGH);
// analogRead(pin);  // 0-1024
// digitalRead(pin); // HIGH or LOW
// delay(ms)