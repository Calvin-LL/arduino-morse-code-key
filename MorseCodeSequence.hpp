#ifndef MORSE_CODE_SEQUENCE_HPP
#define MORSE_CODE_SEQUENCE_HPP

#include <stdlib.h>

// this is the max number of dots and dashes in a morse code sequence
// the +1 is for the null terminator
#define MORSE_SEQUENCE_SIZE (8 + 1)

typedef enum {
  DOT = 0,
  DASH = 1,
  END = 2,
} MorseCodeBit;

// `END` terminated array of MorseCodeBits
class MorseCodeSequence {
 public:
  MorseCodeBit sequence[MORSE_SEQUENCE_SIZE];

  MorseCodeSequence();
  void print();
  static MorseCodeSequence stringToMorseCodeSequence(
      const char* morseCodeString);
};

#endif  // MORSE_CODE_SEQUENCE_HPP