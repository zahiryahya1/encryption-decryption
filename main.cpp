//
//  main.cpp
//  encryption-decryption
//
//  Created by Zahir Yahya on 9/13/16.
//  Copyright (c) 2016 Zahir Yahya. All rights reserved.
//

#include <iostream>
#include "Cipher.hpp"

using namespace std;

// drives the program
int main(int argc, const char * argv[]) {

	string input = "1";
	Cipher cipher;
	
	do {
		if (input != "1" && input != "2" && input != "3") {
			cout <<"\n" + input + " is not a correct input.\n\n";
		}
		
		cout << "Choose a encryption method (1-3).\n\n";
		cout << "1. RSA (generally used to encode a key for a symmetric cipher)\n";
		cout << "2. Ceaser cipher\n";
		cout << "3. Vigenère cipher\n\ninput: ";
		
		cin >> input;
		
	} while (input != "1" && input != "2" && input != "3");
	
	if (input == "1" ) {
		cipher.RSA();
		
	}
	
	if (input == "2" ) {
		cipher.ceaserCipher();
		
	}
	
	if (input == "3" ) {
		cipher.vigenereCipher();
		
	}
	
    return 0;
}
