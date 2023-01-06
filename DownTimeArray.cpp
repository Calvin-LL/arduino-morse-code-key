#include "./DownTimeArray.hpp"
#include <Arduino.h>
#include <limits.h>
#include <stdlib.h>

DownTimeArray::DownTimeArray() {
  clear();
}

void DownTimeArray::add(unsigned long time) {
  if (size < DOWN_TIME_ARRAY_SIZE) {
    downTimeArray[size] = time;
    size++;
  }
}

bool DownTimeArray::isEmpty() {
  return size == 0;
}

MorseCodeSequence DownTimeArray::toMorseCodeSequence() {
  MorseCodeSequence morseCodeSequence;

  if (!isEmpty()) {
    unsigned long maxValue = getMaxValue();
    unsigned long minValue = getMinValue();
    // cut off long dot and dash in millis, dot if shorter than or equal
    // to cut off, dash if longer than cut off
    unsigned int cutOff = (maxValue + minValue) / 2;

    // if the sequence has only one input or the longest to shortest time the
    // key for down for are less than DOT_DASH_MIN_DIFF, set cut off to defult
    if (size == 1 || maxValue - minValue < DOT_DASH_MIN_DIFF) {
      cutOff = DEFAULT_DOT_TIME_LIMIT;
    }

    for (size_t i = 0; i < size; i++) {
      if (downTimeArray[i] <= cutOff) {
        morseCodeSequence.sequence[i] = DOT;
      } else {
        morseCodeSequence.sequence[i] = DASH;
      }
    }

    morseCodeSequence.sequence[size] = END;
  }

  return morseCodeSequence;
}

void DownTimeArray::clear() {
  for (int i = 0; i < size; i++) {
    downTimeArray[i] = 0;
  }
  size = 0;
}

void DownTimeArray::print() {
  Serial.print("DownTimeArray: ");
  for (int i = 0; i < size; i++) {
    Serial.print(downTimeArray[i]);
    Serial.print(" ");
  }
  Serial.println();
}

unsigned long DownTimeArray::getMaxValue() {
  unsigned long maxValue = 0;

  for (int i = 0; i < size; i++) {
    if (downTimeArray[i] != 0) {
      if (downTimeArray[i] > maxValue) {
        maxValue = downTimeArray[i];
      }
    } else {
      break;
    }
  }
  return maxValue;
}

unsigned long DownTimeArray::getMinValue() {
  unsigned long minValue = ULONG_MAX;

  for (int i = 0; i < size; i++) {
    if (downTimeArray[i] != 0) {
      if (downTimeArray[i] < minValue) {
        minValue = downTimeArray[i];
      }
    } else {
      break;
    }
  }
  return minValue;
}