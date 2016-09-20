# encryption-decryption

overview:

Implemented a list of common cryptography methods to encode messages. These methods 
range from a simple alphabet shift, to more complex modular arithmetic. This program 
implements Euclidean Algorithm to check relatively prime, find GCD, and mod inverse.

ciphers:

1) ceaser cipher - basic

  choose a number 0-25 (if larger, then mod 26) and shift the alphabet by that many letters.
    
    ie. abcde...xyz (shift 3)
      defgh...abc 
      
  2) Vigenere - advance ceaser cipher
  
    choose a key word that will shift each letter of the word with its acociated letter.
    ie. key: key ---> 10,4,24,10,04
      text: hello --> 07,4,11,11,14, 
      code: rijvs --> 17,8,15,21,18
      
  3) RSA - advance (not good for messages. better for encoding a key for a different encryption algorithm)
  
   a. choose 2 prime numbers
   b. compute n =qp
   c. phi = (q-1)(p-1)
   d. choose e such that gcd(e, phi) = 1
   e. compute d: d = e^-1 mod phi
   d. converte message into an integer
   e. encrypt: code = message^e (mod phi)
   d. decrypt: message = code^d (mod phi)
