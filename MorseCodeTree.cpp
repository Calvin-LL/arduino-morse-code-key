#include "./MorseCodeTree.hpp"

struct MorseCodeCharacter {
  char character;
  const char morseCode[MORSE_SEQUENCE_SIZE];
};

struct MorseCodeCharacter characterMap[] = {
    {'E', "."},        {'T', "-"},      {'I', ".."},      {'A', ".-"},
    {'N', "-."},       {'M', "--"},     {'S', "..."},     {'U', "..-"},
    {'R', ".-."},      {'W', ".--"},    {'D', "-.."},     {'K', "-.-"},
    {'G', "--."},      {'O', "---"},    {'H', "...."},    {'V', "...-"},
    {'F', "..-."},     {'Ü', "..--"},   {'L', ".-.."},    {'Ä', ".-.-"},
    {'P', ".--."},     {'J', ".---"},   {'B', "-..."},    {'X', "-..-"},
    {'C', "-.-."},     {'Y', "-.--"},   {'Z', "--.."},    {'Q', "--.-"},
    {'Ó', "---."},     {'Š', "----"},   {'5', "....."},   {'4', "....-"},
    {'Ŝ', "...-."},    {'3', "...--"},  {'É', "..-.."},   {'2', "..---"},
    {'&', ".-..."},    {'È', ".-..-"},  {'+', ".-.-."},   {'À', ".--.-"},
    {'1', ".----"},    {'6', "-...."},  {'=', "-...-"},   {'/', "-..-."},
    {'Ĉ', "-.-.."},    {'(', "-.--."},  {'7', "--..."},   {'Ż', "--..-"},
    {'Ń', "--.--"},    {'8', "---.."},  {'9', "----."},   {'0', "-----"},
    {' ', "......"},   {'?', "..--.."}, {'_', "..--.-"},  {'"', ".-..-."},
    {'.', ".-.-.-"},   {'@', ".--.-."}, {'\'', ".----."}, {'-', "-....-"},
    {';', "-.-.-."},   {'!', "-.-.--"}, {')', "-.--.-"},  {'Ź', "--..-."},
    {',', "--..--"},   {':', "---..."}, {'Ś', "...-..."}, {'$', "...-..-"},
    {'\b', "........"}};

MorseCodeTree::MorseCodeTree() {
  for (size_t i = 0; i < MORSE_CODE_TREE_SIZE; i++) {
    morseCodeTree[i] = '\0';
  }
  for (size_t i = 0;
       i < sizeof(characterMap) / sizeof(struct MorseCodeCharacter); i++) {
    MorseCodeSequence sequence =
        MorseCodeSequence::stringToMorseCodeSequence(characterMap[i].morseCode);
    size_t treeIndex = MorseCodeTree::getMorseCodeIndex(sequence);

    morseCodeTree[treeIndex] = characterMap[i].character;
  }
}

size_t MorseCodeTree::getMorseCodeIndex(MorseCodeSequence s) {
  size_t index = 0;
  for (size_t i = 0; s.sequence[i] != END; i++) {
    index = index * 2 + s.sequence[i] + 1;
  }
  return index;
}

char MorseCodeTree::decode(MorseCodeSequence morseArray) {
  return morseCodeTree[getMorseCodeIndex(morseArray)];
}