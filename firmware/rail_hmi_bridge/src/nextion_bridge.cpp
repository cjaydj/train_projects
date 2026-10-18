#include "nextion_bridge.h"

void initialization(unsigned long pcBaud, unsigned long NextionBaud) {
    Serial.begin(pcBaud);
    Serial1.begin(NextionBaud);
}

void sendNextionEndBytes() {
    Serial1.write(0xFF);
    Serial1.write(0xFF);
    Serial1.write(0xFF);
}

void nextionCommandSend(const String& cmd) {
    Serial1.print(cmd);
    sendNextionEndBytes();
}

void handleUSBToNextion() {
if (Serial.available() > 0) {
    String inputcmd = Serial.readStringUntil('\n');
    inputcmd.trim();
    if (inputcmd == "sec_reset") {
        Serial.println("Security Reset Request Sent");
        nextionCommandSend("wepo 0,0");
        nextionCommandSend("va_lockout.val = 0");
        nextionCommandSend("rest");
        nextionCommandSend("page 0");
    }
    if (inputcmd.length() > 0) {
        Serial.print("Send: ");
        Serial.println(inputcmd);
        nextionCommandSend(inputcmd);
    }

    }
}