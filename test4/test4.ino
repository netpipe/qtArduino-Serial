void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming data until newline character
    String data = Serial.readStringUntil('\n');
    
    // Repeat the received data 10 times
    for (int i = 0; i < 10; ++i) {
      // Print the received data followed by a newline character
      Serial.println(data);
      delay(100); // Delay to prevent overwhelming the serial port
    }
  }
}

