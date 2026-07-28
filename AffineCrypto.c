/*
Purpose: Encipher a phrase based on user input (two integers, and a word) and display the original word, equation used, cipher table and ciphertext.

Equation: c = a * p + b mod 26
This is the equation for an affine structure in cryptotography. 
The variable a has to be coprime to 26, namely 1,3,5,7,9,11,15,17,19,21,23,25.
The variable b is any integer mod 26. 
The variable p represents the letter of the alphabet needed to be encoded, with Z=0, A=1, B=2,...Y = 25.
The variable c represtents the encoded letter, with Z=0, A=1, B=2,...Y = 25.
This selection for variable a guarantees an invertible cipher.

Algorithm:
START
	DECLARE CHAR ARRAY Passcode
	DECLARE CHAR ARRAY SecretCode
	DECLARE CHAR Continue
	DO
		PRINT "Select an integer 0 - 25: "
		READ AddInt
		PRINT "Select a number coprime to 26 (1,3,5,7,9,11,15,17,19,21,23,25): "
		READ MultInt
		PRINT "Enter a word: "
		READ Passcode
		FOR (int i = 0; Passcode[i]; i++)
			SecretCode[i] = Passcode[i]
			IF (SecretCode[i] > 96)
				SecretCode[i] = SecretCode[i]-32
			ENDIF
			SecretCode[i] = (SecretCode[i] - 64) % 26
			SecretCode[i] = (SecretCode[i] * MultInt + AddInt) % 26
			IF (SecretCode[i] == 0)
				SecretCode[i] = SecretCode[i] + 26
			ENDIF
			SecretCode[i] = SecretCode[i] + 64
		ENDIF
		PRINT "YOUR PASSCODE: "
		FOR (int i = 0; Passcode[i]; i++)
			PRINT Passcode[i]
		ENDIF
		NEW LINE
		PRINT "EQUATION: c = " MultInt "p + " AddInt " mod 26"
		NEW LINE
		PRINT " CIPHER TABLE: "
		NEWLINE
		FOR (int i = 1; i < 27; i++)
			IF (i % 26 == 0)
				PRINT  "z"
			ELSE 
				PRINT (char) i + 64 + 32
			ENDIF
			PRINT " -- "
			IF ( (i * MultInt + AddInt) % 26 == 0)
				PRINT "Z"
			ELSE
				PRINT (char) ((i * MultInt + AddInt) % 26) + 64
			ENDIF
			NEWLINE
		ENDIF
		PRINT "SECRET CODE: "
		FOR (int i = 0; SecretCode[i]; i++)
			PRINT SecretCode[i]
		ENDIF
		PRINT "Enter another word? (Y/N): 
		READ Continue
	WHILE (Continue == 'Y')
STOP
*/

#include <stdio.h>

int main() {

	char Passcode[100], SecretCode[100], Continue, Table;
	int MultInt, AddInt;

	do {
		printf("Enter an integer 0-25: "); // Get 'b' in the equation
		scanf("%d", &AddInt);
		printf("Enter an integer coprime to 26 (1,3,5,7,9,11,15,17,19,21,23,25): "); // Get 'a' in the equation
		scanf("%d", &MultInt);
		printf("Enter a word: "); // Get a word at most 99 letters
		scanf("%99s", &Passcode);


		for (int i = 0; Passcode[i]; i++) { // Loop through each letter and encode it with our equation

			SecretCode[i] = Passcode[i]; // Copy it to new matrix

			if (SecretCode[i] > 96) { // Turn the character uppercase
				SecretCode[i] = SecretCode[i] - 32;
			}

			SecretCode[i] = (SecretCode[i] - 64) % 26; // Get into mathematical form
			SecretCode[i] = (SecretCode[i] * MultInt + AddInt) % 26; // Use equation to solve a = MultInt, b = AddInt, and p = SecretCode[i]

			if (SecretCode[i] == 0) { // Account for Z = 0 and put it after Y
				SecretCode[i] = SecretCode[i] + 26;
			}


			SecretCode[i] = SecretCode[i] + 64; // Get into Unicode format

			SecretCode[i + 1] = 0; // Make sure the last array value is null
		}

		printf("Equation: c = %d p + %d mod 26\n", MultInt, AddInt); // Display Equation used


		printf("Your Word: "); // Display the user's original word
		for (int i = 0; Passcode[i]; i++) {
			printf("%c", Passcode[i]);
		}
		printf("\n");

		printf("Your Secret Word: "); // Display the user's secret word
		for (int i = 0; SecretCode[i]; i++) {
			printf("%c", SecretCode[i]);
		}
		printf("\n");

		printf("Would you like to see the cipher table? (Y/N): "); // Prompt user to see the cipher table
		scanf(" %c", &Table);

		if (Table == 'Y') { // Displays if user wants more info
			printf("Cipher Table\n");

			for (int i = 1; i < 27; i++) { // Goes through the mathematical alphabet from 1 - 26
				if (i % 26 == 0) {
					printf("z"); // Deals with Z = 0 in math and displays it
				}
				else {
					printf("%c", (char)i + 64 + 32); // Displays the character
				}

				printf(" -- "); // Adds visual pattern for readability

				if ((i * MultInt + AddInt) % 26 == 0) { // Deals with Z = 0 in math and displays it
					printf("Z");
				}
				else {
					printf("%c", (char)((i * MultInt + AddInt) % 26) + 64); // Displays the character
				}

				printf("\n"); // New line needed after each loop
			}
		}

		printf("Would you like to try another word? (Y/N): "); // Prompt user to try again
		scanf(" %c", &Continue);


	} while (Continue == 'Y'); // Loops if user wants to try again

	return 0;
}