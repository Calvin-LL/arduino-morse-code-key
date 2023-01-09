# Arduino Morse Code Key

You can find the instructions to build this project [here](https://www.instructables.com/USB-Arduino-Morse-Code-Key/)

## Morse Code Tree

The Morse Code Tree is a binary tree that stores the morse code for each character. The tree is built using the `MorseCodeTree` class in `MorseCodeTree.cpp`.

Each node in the tree is the character produced by the morse code sequence. The root of the tree is NULL. If the next "morse code bit" is a dot, it is added to the left child of the root. If the next "morse code bit" is a dash, it is added to the right child of the root.

The tree looks something like this:

![Morse Code Tree](https://upload.wikimedia.org/wikipedia/commons/c/ca/Morse_code_tree3.png)

The tree is 511 (2^(8+1)-1) bytes in size since it supports up to 8 "morse code bits" (the longest morse code sequence I added support for is 8 bits long).

## Supported Characters

I implemented all of the characters in [this table on the Wikipedia page for Morse code](https://en.wikipedia.org/wiki/Morse_code#Letters.2C_numbers.2C_punctuation.2C_prosigns_for_Morse_code_and_non-Latin_variants).

You can add characters from the `characterMap` array in `MorseCodeTree.cpp` to support more characters.

| character |   code   |   note    |
| :-------: | :------: | :-------: |
|     E     |    .     |           |
|     T     |    -     |           |
|     I     |    ..    |           |
|     A     |    .-    |           |
|     N     |    -.    |           |
|     M     |    --    |           |
|     S     |   ...    |           |
|     U     |   ..-    |           |
|     R     |   .-.    |           |
|     W     |   .--    |           |
|     D     |   -..    |           |
|     K     |   -.-    |           |
|     G     |   --.    |           |
|     O     |   ---    |           |
|     H     |   ....   |           |
|     V     |   ...-   |           |
|     F     |   ..-.   |           |
|     Ü     |   ..--   |           |
|     L     |   .-..   |           |
|     Ä     |   .-.-   |           |
|     P     |   .--.   |           |
|     J     |   .---   |           |
|     B     |   -...   |           |
|     X     |   -..-   |           |
|     C     |   -.-.   |           |
|     Y     |   -.--   |           |
|     Z     |   --..   |           |
|     Q     |   --.-   |           |
|     Ó     |   ---.   |           |
|     Š     |   ----   |           |
|     5     |  .....   |           |
|     4     |  ....-   |           |
|     Ŝ     |  ...-.   |           |
|     3     |  ...--   |           |
|     É     |  ..-..   |           |
|     2     |  ..---   |           |
|     &     |  .-...   |           |
|     È     |  .-..-   |           |
|     +     |  .-.-.   |           |
|     À     |  .--.-   |           |
|     1     |  .----   |           |
|     6     |  -....   |           |
|     =     |  -...-   |           |
|     /     |  -..-.   |           |
|     Ĉ     |  -.-..   |           |
|     (     |  -.--.   |           |
|     7     |  --...   |           |
|     Ż     |  --..-   |           |
|     Ń     |  --.--   |           |
|     8     |  ---..   |           |
|     9     |  ----.   |           |
|     0     |  -----   |           |
|           |  ......  |   space   |
|     ?     |  ..--..  |           |
|    \_     |  ..--.-  |           |
|     "     |  .-..-.  |           |
|     .     |  .-.-.-  |           |
|     @     |  .--.-.  |           |
|     '     |  .----.  |           |
|     -     |  -....-  |           |
|     ;     |  -.-.-.  |           |
|     !     |  -.-.--  |           |
|     )     |  -.--.-  |           |
|     Ź     |  --..-.  |           |
|     ,     |  --..--  |           |
|     :     |  ---...  |           |
|     Ś     | ...-...  |           |
|     $     | ...-..-  |           |
|   `\b`    | ........ | backspace |
