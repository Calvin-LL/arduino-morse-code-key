#include "./MorseCodeSequence.hpp"
#include <Arduino.h>

MorseCodeSequence::MorseCodeSequence() {
  for (size_t i = 0; i < MORSE_SEQUENCE_SIZE; i++) {
    sequence[i] = END;
  }
}

void MorseCodeSequence::print() {
  Serial.print("MorseCodeSequence: ");
  for (size_t i = 0; i < MORSE_SEQUENCE_SIZE; i++) {
    if (sequence[i] == DOT) {
      Serial.print(".");
    } else if (sequence[i] == DASH) {
      Serial.print("-");
    } else if (sequence[i] == END) {
      Serial.print("|");
      break;
    }
  }
  Serial.println();
}

static MorseCodeSequence MorseCodeSequence::stringToMorseCodeSequence(
    const char* morseCodeString) {
  MorseCodeSequence morseCodeSequence;
  for (size_t i = 0; i < MORSE_SEQUENCE_SIZE; i++) {
    if (morseCodeString[i] == '\0') {
      morseCodeSequence.sequence[i] = END;
    } else if (morseCodeString[i] == '.') {
      morseCodeSequence.sequence[i] = DOT;
    } else if (morseCodeString[i] == '-') {
      morseCodeSequence.sequence[i] = DASH;
    } else {
      morseCodeSequence.sequence[i] = END;
    }
  }
  return morseCodeSequence;
}