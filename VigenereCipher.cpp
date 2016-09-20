#include <stdio.h>
#include "Cipher.hpp"

using namespace std;

void Cipher::vigenereCipher() {
	
	// ask for a key word
	// if capital: for each letter subtract 65 to get the shift val
	// if lower case: for each letter subtract 97 to get the shift val
	// for each char in the key word, use Ceaser Cipher to shift it
	// then add it back to the code text.
	
	string key;
	string text;
	string code;
	
	cout << "\nEnter a key word to encrept the message: ";
	cin.ignore();
	getline( cin, key );
	
	cout << "\nEnter the text that you would like to be encrypted: ";
	//cin.ignore();
	getline( cin, text );
	
	code = encodeVigenere(text, key);
	
	cout << "\n\nThe encoded text:\n" + code;
	
	text = decodeVigenere(code, key);
	
	cout << "\n\nThe decoded text:\n" + text;

}


string Cipher::encodeVigenere(string text, string key) {
	
	string code = "";
	int shift = 0;
	char c = 0;
	int s = 0; // keeps track of the shift increment

	
	for (int i = 0; i < text.length(); i++ ) {
		c = text.at(i);
		shift = key.at( s % key.length() );
		
		// if shift is a capital letter
		if ( shift <= 90 && shift >= 65 ) {
			shift = shift - 65;
			s++;
		}
		
		// if its a lower case letter
		if ( shift <= 122 && shift >= 97 ) {
			shift = shift - 97;
			s++;
		}
		
		else shift = 0;
		
		if ( (c < 65 || ( c > 90  &&  c < 97 ) || c > 122 ) )
			s--;
		
		code += encodeChar(c, shift);
	}
	
	
	return code;
}

string Cipher::decodeVigenere(string code, string key) {
	string text;
	int shift = 0;
	char c = 0;
	int s = 0; // keeps track of the shift increment
	

	for (int i = 0; i < code.length(); i++ ) {
		c = code.at(i);
		shift = key.at( s % key.length() );
		
		// if shift is a capital letter
		if ( shift <= 90 && shift >= 65 ) {
			shift = shift - 65;
			s++;
		}
		
		// if its a lower case letter
		if ( shift <= 122 && shift >= 97 ) {
			shift = shift - 97;
			s++;
		}
		
		else shift = 0;
		
		// skips non letter characters
		if ( (c < 65 || ( c > 90  &&  c < 97 ) || c > 122 ) )
			s--;
		
		text += decodeChar(c, shift);
	}
	
	return text;
}