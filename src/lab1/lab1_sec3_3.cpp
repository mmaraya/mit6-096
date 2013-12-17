//
// The MIT License (MIT)
//
// Copyright (c) 2013 Michael Maraya
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#include <iostream>
using namespace std;

//
// Return true if the supplied number is prime, false otherwise
//
bool isPrime(int number)
{
    // check for negatvies, 0, 1 and 2
    if (number < 0) return false;
    switch (number) {
        case 0:
        case 1:
            return false;
        case 2:
            return true;
    }
    
    // check for other divisors
    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    
    // if there are no other divisors, then it is prime
    return true;
}

//
// 3.3 Prime Numbers
// Write a program to read a number N from the user and then find the first N primes.
// A prime number is a number that only has two divisors, one and itself.
//
int main(int argc, const char *argv[])
{
    int index = 0;
    cout << "Enter number of primes: ";
    cin >> index;
    
    // validate input
    if (index <= 0) {
        cout << "Invalid entry: number of primes must be greater than 0\n";
        return 1;
    }
    
    // loop until we have reached the requested number of primes
    for (int i = 0, j = 0; j < index; i++) {
        if (isPrime(i)) {
            cout << i << ", ";
            j++;
        }
    }
    cout << "\n";
    
    return 0;
}