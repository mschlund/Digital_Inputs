#include "env.h"

blc_bool buttonPressed = false;

extern "C" {
  #include "Digital_Inputs.h"
}

#define LED_PIN 5
#define BUTTON_PIN 9

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  blc_blech_Digital_Inputs_init();
}

void blc_Digital_Inputs_activateLED() {
  digitalWrite(LED_PIN, HIGH);
}

void blc_Digital_Inputs_deactivateLED() {
  digitalWrite(LED_PIN, LOW);
}

void loop() 
{
  buttonPressed = (digitalRead(BUTTON_PIN) == LOW);
  blc_blech_Digital_Inputs_tick();   
  delay(MILLIS_PER_TICK);
}
