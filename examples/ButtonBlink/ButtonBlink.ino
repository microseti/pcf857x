/**
 * This demo code demonstrate all functionnalities of the PCF857X library.
 *
 * PCF8575 pins map :
 * 0: led
 * 1: led
 * 2: led
 * 3: button + pull-up resistor
 */

/* Dependencies */
#include <Wire.h>    // Required for I2C communication
#include "PCF857X.h" // Required for chip PCF8575

/** PCF8575 instance */
PCF857X expander;

/** setup() */
void setup() {

  /* Setup serial for debug */
  Serial.begin(115200);
  
  /* Start I2C bus and PCF8575 instance */
  expander.begin(0x20);
  
  /* Setup some PCF8575 pins for demo */
  expander.pinMode(0, OUTPUT);
  expander.pinMode(1, OUTPUT);
  expander.pinMode(2, OUTPUT);
  expander.pinMode(3, INPUT_PULLUP);
  
  expander.digitalWrite(0, HIGH); // Turn off led 1
}

/** loop() */
void loop() {

  /* Blink demo */
  expander.blink(1, 5, 500); // Blink led 2
  delay(1000);
  expander.blink(2, 5, 500); // Blink led 3
  delay(1000);

  /* DigitalWrite demo */
  expander.digitalWrite(1, HIGH); // Turn off led 2
  delay(500);
  expander.digitalWrite(2, HIGH); // Turn off led 3
  delay(500);
  expander.digitalWrite(1, LOW);  // Turn on led 2
  delay(500);
  expander.digitalWrite(2, LOW);  // Turn on led 3
  delay(500);

  /* Toggle demo */
  expander.toggle(1);  // Toggle led 2
  expander.toggle(2);  // Toggle led 3
  delay(1000);
  expander.toggle(1);  // Toggle led 2
  expander.toggle(2);  // Toggle led 3
  delay(1000);

  /* Direct pins acces demo (does not with input setup) */
  //expander.write(255); // All led off
  //delay(1000);
  //expander.write(0);   // All led on
  //delay(1000);

  /* DigitalRead demo */
  // PRESS THE BUTTON NOW (if you want to press it) !
  Serial.println(expander.digitalRead(3) ? "HIGH" : "LOW"); // Print button pin state
  Serial.println(expander.read(), DEC); // Read the whole pins input register

  /* Final demo (warning: will make button bug) */
  //expander.set();   // All led off
  //delay(1000);
  //expander.clear(); // All led on
  delay(5000);
}
