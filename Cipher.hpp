#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Cipher {

public:
	void RSA();
	string encodeRSA( string text );
	string decodeRSA( string code );
	
	void ceaserCipher();
	string encodeCeaser( string text, int shift );
	string decodeCeaser( string code, int shift );
	char encodeChar( int c, int shift );
	char decodeChar( int c, int shift );
	
	
	void vigenereCipher();
	string encodeVigenere( string text, string key);
	string decodeVigenere( string code, string key);
	
	
	bool isPrime(long int p);
	bool relativelyPrime(long int a, long int b);
	
	void calcE( vector< long int > &vec, const long int &e, const long int &totient,
			    const long int &p, const long int &q );
	long int calcD(const long int &e, const long int &totient);
	
	// long int modInverse( const long int &e, const long int &totient );
	
	long int gcdExtended(long int a, long int b, long int *x, long int *y);
	
	long int modInverse(long int a, long int m);
	
};