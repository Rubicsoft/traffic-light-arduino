/*
  Traffic Light (Red, Yellow, Green)
  Code by Reymo Je

  PINS
  3 : red light
  4 : yellow light
  5 : green light
  7 : buzzer
*/


#define LIGHT_DELAY 2
#define BUZZER_PIN 7

int led_pins[3] = {3, 4, 5};


// Supporting Functions
void traffic_light(float delay);
void yell_buzzer(float buzz_time = 0.2);



void setup() {
  // Set the led pins to output
  for(int pin : led_pins) {
    pinMode(pin, OUTPUT);
  }

  // Set the buzzer pin to output
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  traffic_light(LIGHT_DELAY);
}


/* ------ SUPPORTING FUNCTIONS ------ */

// Turn on/off the Red, Yellow, and Green LEDs with delay
void traffic_light(float delay_time) {
  for(int pin : led_pins) {
    digitalWrite(pin, HIGH);

    yell_buzzer();

    delay(long(delay_time * 1000));
    digitalWrite(pin, LOW);
  }
}

// Turn on a buzzer (pin 7) for a while of time
void yell_buzzer(float buzz_time) {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(long(buzz_time * 1000));
  digitalWrite(BUZZER_PIN, LOW);
}