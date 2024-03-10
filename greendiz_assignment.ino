// LM35 Temperature Sensor pin connected to Arduino Analog pin A0
const int sensor_pin = A0;
const int led_pin = 13;  // Onboard LED pin

// Temperature thresholds in Celsius
const int low_tempthreshold = 30;
const int high_tempthreshold = 30;

// Blink intervals in milliseconds
const int low_tempblinkinterval = 250;
const int high_tempblinkinterval = 500;

void setup() {
  pinMode(led_pin, OUTPUT); //here led blinking is output
  Serial.begin(9600); //baudrate
}

void loop() {
  int temperature = readTemperature(); //reading temperature value from input
 //checking the given conditions
  if (temperature < low_tempthreshold) { 
    blinkLED(low_tempblinkinterval);
  } else if (temperature > high_tempthreshold) {
    blinkLED(high_tempblinkinterval);
  }
}

int readTemperature() {
  int sensor_value = analogRead(sensor_pin);
  // Convert analog reading to temperature in Celsius
  float voltage = sensor_value * (5.0 / 1023.0);
  int temperature = (voltage - 0.5) * 100;
  return temperature;
}

void blinkLED(int interval) {
  digitalWrite(led_pin, HIGH); // to make the led high
  delay(interval);
  digitalWrite(led_pin, LOW); // to make the led low
  delay(interval);
}
