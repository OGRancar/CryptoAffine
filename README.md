# CryptoAffine

A C implementation of the Affine cipher demonstrating modular arithmetic, invertible transformations, and applications of abstract algebra in cryptography.


# Description

1. Prompts the user to enter in an Additive Key. Although this number can be anything, it makes sense to use 0-25 only since the modulus of 26 creates equivalence classes.
2. Prompts the user to enter in a Multiplicative Key. This number must be coprime to 26 (the size of the English alphabet) to preserve a mathematical field (ensuring inverses exist.
3. Prompts the user to enter a word to encipher using both of their keys. The word is capped at 99 letters.
4. Displays the user information about the specific equation used to encipher the word as well both the original word and the new enciphered word.
5. Asks user if they want to see more information about the letter mappings used to create the algebraic system.
6. Asks user if they want to try again. (Fully repeatable)


# Future Updates

1. Make the code more readable.
2. Create a deciphering tool.
3. Create a decrypting tool? (Not useful for words/short statements)


