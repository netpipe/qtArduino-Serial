#define BUFFER_SIZE 64 // Define the size of the buffer

char buffer[BUFFER_SIZE]; // Create a buffer to store data
int bufferIndex = 0; // Index to track the current position in the buffer

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Example: Reading data from sensors and storing it in the buffer
  int sensorValue = analogRead(A0);
  sprintf(buffer + bufferIndex, "%d\n", sensorValue); // Append sensor data to buffer
  bufferIndex += strlen(buffer + bufferIndex); // Update buffer index

  // Check if buffer is full or if we encounter a newline character
  if (bufferIndex >= BUFFER_SIZE || buffer[bufferIndex - 1] == '\n') {
    // Send the first line of the buffer over serial
    for (int i = 0; i < bufferIndex; i++) {
      Serial.write(buffer[i]); // Send each character of the line
      if (buffer[i] == '\n') {
        break; // Stop sending when newline character is encountered
      }
    }

    // Shift the remaining data in the buffer to the beginning
    int remainingLength = bufferIndex - (strchr(buffer, '\n') - buffer + 1);
    memmove(buffer, buffer + strchr(buffer, '\n') - buffer + 1, remainingLength);
    bufferIndex = remainingLength; // Update buffer index

    // Clear the remaining part of the buffer
    memset(buffer + bufferIndex, 0, BUFFER_SIZE - bufferIndex);
  }

  // Add some delay to prevent flooding the serial port
  delay(1000);
}

