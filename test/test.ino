void setup() {
  Serial.begin(115200); // Initialize serial communication with baud rate 9600
}

void loop() {
  if (Serial.available()) { // Check if data is available to read
    char receivedChar = Serial.read(); // Read the incoming byte
    Serial.print("Received: ");
    Serial.println(receivedChar); // Print the received character
  }
}
