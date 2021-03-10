#include <iostream>
#include <fstream>
#include "CharacterCounter.h"

using namespace std;

int main(int argc, char* argv[]) {

	if (argc < 2) {

		cerr << "Arguments missing." << endl;
		cerr << "Usage: CharacterCounter <filename> " << endl;

		return 1;
	}

	//Create text input for the character counter.
	ifstream lInput(argv[1], ifstream::binary);

	//In case of fail operation, we need to help users to notice their problem.
	if (!lInput.good()) {
		cerr << "Cannot open input file: " << argv[1] << endl;

		return 2;
	}

	// Create character counter
	CharacterCounter lCounter;

	//local variable to read character (without whitespace)
	unsigned char lChar;
    
	//including the whitespace
	lInput.unsetf(ios::skipws);

	// the counting process for character in the file.
	while (lInput >> lChar) {
		lCounter.count(lChar);

	}

	//print the result
	cout << lCounter;
	
	//Program suceeded.
	return 0;

}
