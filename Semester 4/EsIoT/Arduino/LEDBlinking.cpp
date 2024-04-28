// initialize digital pin LED_BUILTIN as an output.
const int LED_PIN = 13; // Define the pin number for the LED

void setup(){
  pinMode(LED_PIN, OUTPUT); // Set the LED pin as an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_PIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                  // wait for a second
  digitalWrite(LED_PIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                  // wait for a second
}
