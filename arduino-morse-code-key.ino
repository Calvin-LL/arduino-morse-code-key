#include <Keyboard.h>
#include "./DownTimeArray.hpp"
#include "./MorseCodeTree.hpp"

#define MORSE_KEY_INPUT_PIN 2
#define BUZZER_PIN 3
// time in millis to wait for before trying to decode the sequence
#define DECODE_TIME_LIMIT 500

unsigned long lastDownMillis = 0;
unsigned long lastUpMillis = 0;

MorseCodeTree morseCodeTree;
DownTimeArray downTimeArray;

void setup() {
  // Serial.begin(9600); // debugging
  Keyboard.begin();
  pinMode(MORSE_KEY_INPUT_PIN, INPUT_PULLUP);
}

void loop() {
  int morseKeyInputState = digitalRead(MORSE_KEY_INPUT_PIN);
  bool isMorseKeyDown = morseKeyInputState == LOW;
  unsigned long now = millis();

  if (isMorseKeyDown) {
    // get the millis when first pressed down
    if (lastDownMillis == 0) {
      lastDownMillis = now;
    }
  } else {
    // if the key was down before
    if (lastDownMillis != 0) {
      // how long was the key down for
      unsigned long downTime = now - lastDownMillis;

      // if down for more than 20 millis, helps avoid accidental presses
      if (downTime > 20) {
        lastDownMillis = 0;

        if (downTime > 30) {
          downTimeArray.add(downTime);
        }

        lastUpMillis = now;
      }
    }

    // if key has been up
    if (lastUpMillis != 0) {
      unsigned long upTime = now - lastUpMillis;

      // if key has been up for longer than DECODE_TIME_LIMIT
      if (upTime > DECODE_TIME_LIMIT) {
        MorseCodeSequence morseCodeSequence =
            downTimeArray.toMorseCodeSequence();
        char c = morseCodeTree.decode(morseCodeSequence);

        // debugging:
        // downTimeArray.print();
        // morseCodeSequence.print();
        // Serial.println(c);
        // Serial.println(c, DEC);

        if (c != '\0') {
          Keyboard.print(c);
        }

        downTimeArray.clear();

        lastUpMillis = 0;
      }
    }
  }

  // tuen on buzzer if key is down
  if (isMorseKeyDown) {
    tone(BUZZER_PIN, 700);
  } else {
    noTone(BUZZER_PIN);
  }
}