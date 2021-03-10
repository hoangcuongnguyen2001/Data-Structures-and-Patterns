// Tutorial 2, 2021.

#include "CharacterCounter.h"

using namespace std;


// Constructors is defined here...
CharacterCounter::CharacterCounter() {
	
	for (size_t i = 0; i < 256; i++) {
		fCharacterCount[i] = 0;
	}

	fTotalNumberofCharacter = 0;
}

void CharacterCounter::count(unsigned char aCharacter) {

	fCharacterCount[aCharacter]++;
	fTotalNumberofCharacter++;
}

std::ostream& operator<< (std::ostream& aOstream, const CharacterCounter& aCharacterCounter) {

	aOstream << "Character count for " << aCharacterCounter.fTotalNumberofCharacter << " characters: " << endl;

	for (size_t i = 0; i < 256; i++) {

		if (aCharacterCounter.fCharacterCount[i] > 0) {

			aOstream << static_cast<char>(i) << ":\t"
				<< aCharacterCounter.fCharacterCount[i] << endl;
		}

		
	}
	return aOstream;
}