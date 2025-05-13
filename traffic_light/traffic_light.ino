/*
  Traffic Light (Red, Yellow, Green)
  Created by Reymo Je

  PINS
  2 : red light
  4 : yellow light
  7 : green light
  9 : buzzer
  A1 : potentiometer

*/


/* USER CONFIG */
#define MIN_DELAY 0.2
#define MAX_DELAY 5
#define ENABLE_BUZZER false
#define BUZZ_TIME 0.1


#define BUZZER_PIN 9
#define POT_PIN A1

void traffic_light(float delay);
void yell_buzzer(float buzz_time);


unsigned int led_pins[3] = {2, 4, 7};
unsigned long traffic_delay;



void setup() {
  // Set the led pins to output
  for(int pin : led_pins) {
    pinMode(pin, OUTPUT);
  }

  // Set the buzzer pin to output
  #if ENABLE_BUZZER
  pinMode(BUZZER_PIN, OUTPUT);
  #endif

  Serial.begin(9600);
}

void loop() {
  traffic_delay = map(analogRead(POT_PIN), 0, 1023, long(MAX_DELAY * 1000), long(MIN_DELAY * 1000));
  Serial.println(traffic_delay);

  traffic_light(traffic_delay);
}


/* SUPPORTING FUNCTIONS */

// Turn on/off the Red, Yellow, and Green LEDs with delay
void traffic_light(unsigned long delay_time) {
  for(int pin : led_pins) {
    digitalWrite(pin, HIGH);

    #if ENABLE_BUZZER
    yell_buzzer(BUZZ_TIME);
    #endif

    delay(delay_time);
    digitalWrite(pin, LOW);
  }
}

#if ENABLE_BUZZER
// Turn on a buzzer (pin 7) for a while of time
void yell_buzzer(float buzz_time) {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(long(buzz_time * 1000));
  digitalWrite(BUZZER_PIN, LOW);
}
#endif