// Tutorial 3, Semester 1, 2021.

#include "Polynomial.h";


//Constructor is defined here:
Polynomial::Polynomial() {
	fDegree = 0;
	for (int i = 0; i < MAX_DEGREE; i++) {
		fCoeffs[i] = 0;
	}
}

// Definition of multiplication operator of polynomial:
Polynomial Polynomial::operator*(const Polynomial& aRHS) const {

	Polynomial lResult;

	lResult.fDegree = fDegree + this->fDegree;


	// coefficients loop from both degrees of both polymonials.
	for (int i = fDegree; i >= 0; i--) {
		
		for (int j = aRHS.fDegree; j >= 0; j--) {

			lResult.fCoeffs[i + j] += fCoeffs[i] * aRHS.fCoeffs[j];
		}
	}

	return lResult;

}

// Definition for comparison operators.
bool Polynomial::operator==(const Polynomial& aRHS) const
{
	for (int i = 0; i < fDegree; i++) {
		if (!(fCoeffs[i] == aRHS.fCoeffs[i])) {
			return false;
		}
		else {
			return true;
		}
	}
	
}


//Input(Pull the coefficients to the program)
std::istream& operator>>(std::istream& aIStream, Polynomial& aObject) {

	int aDegree;
	aIStream >> aDegree;
	aObject.fDegree = aDegree + 1;
	for (int i = aObject.fDegree; i >= 0; i--) {
		aIStream >> aObject.fCoeffs[i];
	}

	return aIStream;

}


// Output(Push the answer)
std::ostream& operator<<(std::ostream& aOStream, const Polynomial& aObject) {

	aOStream << aObject.fCoeffs[aObject.fDegree] << "x^" << aObject.fDegree;
	for (int i = aObject.fDegree - 1; i >= 0; i--) {
		if (aObject.fCoeffs[i] != 0.0) {

			aOStream << " + " << aObject.fCoeffs[i] << "x^" << i;
		}
	}

	aOStream << std::endl;

	return aOStream;

}