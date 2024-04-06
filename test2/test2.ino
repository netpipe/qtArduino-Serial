#define BUFFER_SIZE 64 // Define the size of the buffer

char buffer[BUFFER_SIZE]; // Create a buffer to store data
int bufferIndex = 0; // Index to track the current position in the buffer

void setup() {
  Serial.begin(115200); // Initialize serial communication
}

void loop() {
  // Example: Reading data from sensors and storing it in the buffer
  int sensorValue = analogRead(A0);
  sprintf(buffer + bufferIndex, "%d\n", sensorValue); // Append sensor data to buffer
  bufferIndex += strlen(buffer + bufferIndex); // Update buffer index

  // Check if buffer is full or if we encounter a newline character
  if (bufferIndex >= BUFFER_SIZE || buffer[bufferIndex - 1] == '\n') {
    // Send the contents of the buffer over serial
    Serial.print(buffer);

    // Clear the buffer and reset the buffer index
    memset(buffer, 0, BUFFER_SIZE);
    bufferIndex = 0;
  }

  // Add some delay to prevent flooding the serial port
  delay(1000);
}
