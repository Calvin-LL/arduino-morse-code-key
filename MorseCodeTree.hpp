#ifndef MORSE_CODE_TREE_HPP
#define MORSE_CODE_TREE_HPP

#include "./MorseCodeSequence.hpp"

// a tree implemented as an array
// a dot is a left child, a dash is a right child
// the root is null
// each node is a character

#define MORSE_CODE_TREE_SIZE ((1 << MORSE_SEQUENCE_SIZE) - 1)

class MorseCodeTree {
 private:
  char morseCodeTree[MORSE_CODE_TREE_SIZE];

  static size_t getMorseCodeIndex(MorseCodeSequence morseSq);

 public:
  MorseCodeTree();
  char decode(MorseCodeSequence morseSq);
};

#endif  // MORSE_CODE_TREE_HPP