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
// 2.2 Hello World II
// Write a program that outputs “Hello, World!” n times (where n is a nonnegative
// integer that the user will input) with:
//
// • a for loop.
// • a while loop.
// • a do...while loop.
//
int main(int argc, const char *argv[])
{
    int n {0};
    
    cout << "Please enter the number of times to repeat: ";
    cin >> n;
    
    // for loop
    for (int i = 0; i < n; i++) {
        cout << "Hello, World II A!\n";
    }
    
    // while loop
    int j = n;
    while(j-- > 0) {
        cout << "Hello, World II B!\n";
    }
    
    // do ... while
    int k = n;
    if (k > 0) {
        do {
            cout << "Hello, World II C!\n";
        } while (--k > 0);
    }
    
    return 0;
}