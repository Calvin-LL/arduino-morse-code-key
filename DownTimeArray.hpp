#ifndef DOWN_TIME_ARRAY_HPP
#define DOWN_TIME_ARRAY_HPP

#include "./MorseCodeSequence.hpp"

// how many millis does the longest and shortest millis in the sequence have to
// be to consider them all the same length
#define DOT_DASH_MIN_DIFF 100
// if all millis in the sequence are roughly the same length, how short in
// millis is a dot
#define DEFAULT_DOT_TIME_LIMIT 250
// length of the array that stores the current sequence
#define DOWN_TIME_ARRAY_SIZE 20

// null terminated array of unsigned longs
class DownTimeArray {
 public:
  DownTimeArray();
  void add(unsigned long time);
  bool isEmpty();
  MorseCodeSequence toMorseCodeSequence();
  void clear();
  void print();

 private:
  unsigned long downTimeArray[DOWN_TIME_ARRAY_SIZE];
  size_t size;

  unsigned long getMaxValue();
  unsigned long getMinValue();
};

#endif  // DOWN_TIME_ARRAY_HPP