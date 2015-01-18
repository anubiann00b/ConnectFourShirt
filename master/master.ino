#include "SoftwareSerial.h"
#include "Event.h"
#include "Timer.h"

int FIRST_COL = 0;
int FIRST_ROW = 0;

int NUM_COLS = 14;
int NUM_ROWS = 6;

int NUM_INPUTS = 6;
int FIRST_INPUT = 4;
int FIRST_INPUT_COL = 0;

int BLUE_PLAYER = 1;
int GREEN_PLAYER = 2;

int grid[6][14] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

SoftwareSerial comms(2,3);
Timer timer;

int currentRow = 0;
int currentPlayer = BLUE_PLAYER;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting");
  comms.begin(9600);
  timer.every(20, pollInputs);
  timer.every(10, updateGrid);
  comms.write('r');
}

void loop() {
  timer.update();
  char c = comms.read();
  if (c != -1) {
    switch (c) {
        case 'i':
          handleInput(comms.read() - '0');
          break;
        default:
          break;
    }
  }
}

void updateGrid() {
  pinMode(currentRow+FIRST_ROW, INPUT);

  currentRow++;
  if (currentRow > NUM_ROWS)
    currentRow = 0;

  pinMode(currentRow+FIRST_ROW, OUTPUT);
  digitalWrite(currentRow+FIRST_ROW, HIGH);

  for (int i=0;i<NUM_COLS;i++)
    comms.write(grid[currentRow][i]);
}

void pollInputs() {
  for (int i=0;i<NUM_INPUTS;i++) {
    int a = analogRead(i+FIRST_INPUT);
    if (a < 338)
      handleInput(i+FIRST_INPUT_COL);
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