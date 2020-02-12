/*
        HANGMAN
*/
#include <iostream>
#include <string>
#include <random>
#include <ctype.h>

using namespace std;

void fillLetters (char, string);
int chooseRandomCountry ();
void pauseConsole ();
void printGameBoard (string);
char processUserInput ();
void clearConsole ();
bool isGameDone (string);
void printGameOver (string guess);
bool isGameSuccessful (string currentGuess);
void printNumberOfTries ();

const int numCountries = 30;
int padding = 3; 


const int maxNumberGuesses = 4;
int currentGuessNumber = 0;
string currentGuessString = "";
string correctCountry = "";

string countries [] = {
    "senegal",
    "serbia",
    "seychelles",
    "singapore",
    "slovakia",
    "slovenia",
    "somalia",
    "spain",
    "sudan",
    "suriname",
    "swaziland",
    "sweden",
    "switzerland",
    "syria",
    "taiwan",
    "tajikistan",
    "tanzania",
    "thailand",
    "togo",
    "tonga",
    "tunisia",
    "turkey",
    "turkmenistan",
    "tuvalu",
    "uganda",
    "ukraine",
    "uruguay",
    "uzbekistan",
    "vanuatu",
    "venezuela",
};

int main () {
    clearConsole();

    correctCountry = countries[chooseRandomCountry()];

	currentGuessString = std::string(correctCountry.length(), '*');

    while (isGameDone(currentGuessString) == false) {
        printGameBoard(currentGuessString);
        printNumberOfTries();
        char userGuess = processUserInput();
        fillLetters(userGuess, correctCountry);
		
        clearConsole();
    }

    printGameOver(currentGuessString);
}

bool isGameDone (string currentGuess) {
	
	//If the number of guess is greater than the max number of guesses
	//or if the current guesses all together are correct, then the game
	//is done...
	if (currentGuessNumber >= maxNumberGuesses || currentGuessString == correctCountry) {
		return true;
	}
	//...otherwise, the game isn't done
	else {
		return false;
	}
	
}

bool isGameSuccessful (string currentGuess) {
	
	//If all of the user's guesses together are correct, then the user
	//won the game...
	if (currentGuessString == correctCountry) {
		return true;
	}
	//...otherwise, the user didn't win the game
	else {
		return false;
	}
    
}

void printGameOver (string currentGuess) {
   
	//If the function "isGameSuccessful" is true, then the program says
	//"CONGRATS"...
	if (isGameSuccessful(currentGuess) == true) {
		std::cout << "CONGRATS" << endl;
	}
	//...otherwise the program says "YOU FAILED"
	else {
		std::cout << "YOU FAILED" << endl;
	}
	
}

void printGameBoard (string guess) {
    
	//First Line
	std::cout << "+";
	for (int i = 0; i < (guess.length()+ (2 * padding)) - 2; i++) {
		std::cout << "-";
	}
	std::cout << "+";
	std::cout << endl;
	
	//Second Line
	std::cout << "|";
	for (int i = 0; i < padding - 1; i++) {
		std::cout << " ";
	}
	std::cout << currentGuessString;
	for (int i = 0; i < padding - 1; i++) {
		std::cout << " ";
	}
	std::cout << "|";
	std::cout << endl;

	//Third Line
	std::cout << "|";
	for (int i = 0; i < padding - 1; i++) {
		std::cout << " ";
	}
	for (int i = 0; i < guess.length(); i++) {
		std::cout << "_";
	}
	for (int i = 0; i < padding - 1; i++) {
		std::cout << " ";
	}
	std::cout << "|";
	std::cout << endl;

	//Fourth Line
	std::cout << "+";
	for (int i = 0; i < (guess.length() + (2 * padding)) - 2; i++) {
		std::cout << "-";
	}
	std::cout << "+";
	std::cout << endl;

}

void printNumberOfTries () {
	
	//Prints out the number of tries, starting at zero
	std::cout << "NUMBER OF TRIES: " << currentGuessNumber << endl;
	
}

char processUserInput () {
    
	//Prints out, "Enter a Guess!: " and takes the guess from the user,
	//returns the value of the user's guess
	char userGuess;
	std::cout << "Enter a Guess!: ";
	cin >> userGuess;
	return userGuess;

}

void fillLetters (char guessChar, string secretWord) {
	
	//The for loop checks to see if what the user inputed is correct, if it
	//isn't correct, then it adds one to "currentGuessNumber" and if it is
	//correct, then it replaces the *'s in currentGuessString with the char
	//the user inputed, and it doesn't add one to "currentGuessNumber"
		bool letterNotFound = true;
		for (int i = 0; i < secretWord.length(); i++) {

			if (secretWord[i] == guessChar && currentGuessString[i] != guessChar) {
				currentGuessString[i] = guessChar;
				letterNotFound = false;
			}
			
		}
		if (letterNotFound == true) {
			currentGuessNumber++;
		}
		 }
	
void pauseConsole () {
    std::string temp;
    std::cout << "Enter to continue... ";
    std::getline(std::cin, temp);
}

void clearConsole () {
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    	system("cls");
    #else
        system("clear");
    #endif
}

int chooseRandomCountry () {
    random_device seed;
    default_random_engine engine(seed());
    uniform_int_distribution<int> dist(0, numCountries-1);

    return dist(engine);
}
