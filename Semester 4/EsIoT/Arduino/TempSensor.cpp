const int hot = 50;   // set hot parameter
const int ledPin = 7; // set LED pin

void setup()
{
    pinMode(A2, INPUT);      // sensor
    pinMode(ledPin, OUTPUT); // red LED
    Serial.begin(9600);
}

void loop()
{
    int sensor = analogRead(A2);
    float voltage = (sensor / 1024.0) * 5.0;
    float tempC = (voltage - 0.5) * 100;
    float tempF = (tempC * 1.8) + 32;
    Serial.print("temp: ");
    Serial.print(tempF);

    if (tempF > hot)
    { // hot
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        delay(500);
        Serial.println(" It's Hot.");
    }
    else
    { // fine
        digitalWrite(ledPin, LOW);
        Serial.println(" It's Fine.");
    }
    delay(10);
}
