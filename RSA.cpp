#include <stdio.h>
#include <math.h>
#include <vector>
#include "Cipher.hpp"

using namespace std;

// descrete log problem
// rsa is used to encode a key, and the actual message is encoded
// by a symmetric crypto algorithm such as AES

void Cipher::RSA() {
	char text[8];
	long int p;
	long int q;
	long int e;
	long int totient;
	long int d;
	long int n;
	bool exit = false;
	vector<long int> ePossible;
	
	// get first prime
	do {
	cout << "\nEnter a prime number p: ";
	cin >> p;
	
		if (isPrime(p))
			exit = true;
		else
			cout << endl << p << " is not prime.\n";
		
		
	} while ( exit != true );
	
	// get second prime
	exit = false;
	do {
		cout << "\nEnter a prime number q: ";
		cin >> q;
		
		if (isPrime(q))
			exit = true;
		else
			cout << endl << q << " is not prime.\n";
		
		
	} while ( exit != true );
	
	n = p*q;
	totient = (p-1) * (q-1);
	cout << "\nPublic value of N: " << n << endl;

	
	calcE(ePossible, e, totient, p, q);
	
	//print out possible values of e
	cout << "\nPossible values of 'e' are: ";
	for( int i = 0; i < ePossible.size(); i++ )
		cout << ePossible[i] << ", ";
	
	exit = false;
	do {
		cout << "\n\nEnter a integer 'e' that is coprime to " << totient
		<< " (ie. gcd(e, " << totient << ") = 1\ne: ";
		cin >> e;
		
		if (relativelyPrime(totient, e))
			exit = true;
		else {
			cout << endl << e << " is not coprime to " << totient << ".\n";
			cout << "\nPossible public values of 'e' are: ";
			
			for( int i = 0; i < ePossible.size(); i++ )
				cout << ePossible[i] << ", ";

		}
		
	} while ( exit != true );

	
	// Enter a message
	// convert message into an interger less then N
	// DOG -> 3*(26^2) + 14*26^1 + 6*26^0
	
	d = calcD( e, totient );
	cout << "\nThe secret value of d: " << d << endl;
	
	
}





bool Cipher::isPrime( long int p ) {
	
	if ( p == 0 )
		return false;
	
	if ( p == 1 )
		return true;
	
	if ( p == 2 )
		return true;
	
	if ( p == 3 )
		return true;
	
	if ( p == 5 )
		return true;
	
	if ( p % 2 == 0 )
		return false;
	
	if ( p % 3 == 0 )
		return false;
	
	if ( p % 5 == 0 )
		return false;
	
	for ( int i = 5; i < sqrt( p ) + 1; i+=2 )
	{
		if (p % i == 0)
			return false;
	}
	
	return true;
}

// uses eclidean algorith in 6 lines found on stackverflow
bool Cipher::relativelyPrime(long int a, long int b) { // Assumes a, b > 0
	for ( ; ; ) {
		if (!(a %= b)) return b == 1 ;
		if (!(b %= a)) return a == 1 ;
	}
}

// creates a list of possible values of e and puts it into an array
void Cipher::calcE(vector< long int > &vec, const long int &e, const long int &totient,
				   const long int &p, const long int &q) {
	for (int i = 2; i < totient; i ++ ) {
		if ( relativelyPrime(i, totient) && (i % p != 0) && (i % q != 0) ) {
			vec.push_back(i);
		}
	}
}
// find the inverse of e ( e^-1 = d mod(totient) )
long int Cipher::calcD(const long int &e, const long int &totient) {
	return modInverse( e, totient );
}



// extended Euclidean Algorithm
long int gcdExtended(long int a, long int b, long int *x, long int *y);

// Function to find modulo inverse of a found on geeks for geeks
long int Cipher::modInverse(long int a, long int m) {
	long int x, y;
	long int g = gcdExtended(a, m, &x, &y);
	if (g != 1)
		cout << "Inverse doesn't exist";
	else {
		// m is added to handle negative x
		long int res = (x%m + m) % m;
		return res;
	}
	
	cout << "/n/nshouldnt happen!/n";
	return 0;
}

// extended Euclidean Algorithm
long int Cipher::gcdExtended(long int a, long int b, long int *x, long int *y) {
	// Base Case
	if (a == 0) {
		*x = 0, *y = 1;
		return b;
	}
 
	long int x1, y1; // To store results of recursive call
	long int gcd = gcdExtended(b%a, a, &x1, &y1);
 
	// Update x and y using results of recursive
	// call
	*x = y1 - (b/a) * x1;
	*y = x1;
 
	return gcd;
}

