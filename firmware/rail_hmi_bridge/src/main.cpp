#include <Arduino.h>
#include "nextion_bridge.h"


void setup() {
  initialization();
}

void loop() {
  handleUSBToNextion();
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}