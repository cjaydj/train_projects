#pragma once
#include <Arduino.h>

void initialization(unsigned long pcBaud = 115200, unsigned long nextionBaud = 9600);
void nextionCommandSend(const String& cmd);
void sendNextionEndBytes();
void handleUSBToNextion();