#include <stdio.h>
#include "Cipher.hpp"

using namespace std;

void Cipher::ceaserCipher() {
	string text = "";
	string code = "";

	int shift = 0;

	cout << "\nEnter the shift number (an incorect input will result as '0'): ";
	cin >> shift;

	
	cout << "\nEnter the text that you would like to be encrypted: ";
	cin.ignore();
	getline( cin, text );
	
	code = encodeCeaser( text, shift);
	
	cout << "\n\nThe encoded text:\n" + code;
	
	text = decodeCeaser( code, shift);
	
	cout << "\n\nThe decoded text:\n" + text;
	
	
}

string Cipher::encodeCeaser( string text, int shift) {
	string code = "";
	int curr = 0;
	shift = shift % 26;
	
	// loop through the string and for each char, shift it then concatinate it to
	// the new string
	for (int i = 0; i < text.length(); i++ ) {
		curr = text.at(i);
		code+=encodeChar( curr, shift );
	}
	
	return code;
}


string Cipher::decodeCeaser(string code, int shift) {
	string text = "";
	int curr = 0;
	shift = shift % 26;
	
	// loop through the enoded text and for each char, shift it then concatinate
    // it to the new string
	for (int i = 0; i < code.length(); i++ ) {
		curr = code.at(i);
		text+= decodeChar( curr, shift);
	}
	
	return text;
}

char Cipher::encodeChar(int c, int shift) {
	
	char code = 0;
	
	
	// if the current char is a letter
	if ( ( 65 <= c && c <= 90 ) || ( 97 <= c && c <= 122 ) ) {
		c+=shift;
		
		// if the old char was a lowercased word
		if (122 < c && ( (c - shift) <= 122 && ( 97 <= (c - shift) ) ) )
			c = c - 26;
		
		
		// if the old char was a capital letter
		else if (90 < c && ( (c - shift) <= 90 && ( 65 <= (c - shift) ) ) )
			c = c - 26;
		
		code+=c;
	}
	
	else code+=c;

	return code;
}

char Cipher::decodeChar(int c, int shift) {
	
	char letter = 0;
	
	// if the current char is a letter
	if ( ( 65 <= c && c <= 90 ) || ( 97 <= c && c <= 122 ) ) {
		c-=shift;
		
		// if the old char was a lowercased word
		if (97 > c && ( (c + shift) <= 122 && ( 97 <= (c + shift) ) ) )
			c = c + 26;
		
		
		// if the old char was a capital letter
		else if (65 > c && ( (c + shift) <= 90 && ( 65 <= (c + shift) ) ) )
			c = c + 26;
		
		letter+=c;
	}
	else letter+=c;
	
	return letter;
}

