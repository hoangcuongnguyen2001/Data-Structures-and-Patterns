#pragma once

#include <iostream>

class CharacterCounter {

private:
	size_t fTotalNumberofCharacter;
	size_t fCharacterCount[256];         // All of 256 bits are counted.

public:
	CharacterCounter();

	void count(unsigned char aCharacter);

	// This method can use both private data types here...
	friend std::ostream& operator<< ( std::ostream& aOstream,
		const CharacterCounter& aCharacterCounter);
};
