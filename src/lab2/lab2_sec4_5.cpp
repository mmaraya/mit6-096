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
// 4.5
// Write a single sum function capable of handling an arbitrary number of integers.
// It should take two arguments, include a loop, and return an integer. (Hint: What
// data types can you use to represent an arbitrarily large set of integers in two
// arguments?)
//

int sum(const int elements, const int *array)
{
    int result = 0;
    for (int i = 0; i < elements; i++) {
        result += array[i];
    }
    return result;
}

int main(int argc, const char *argv[])
{
    int a[] = {3, 5};
    int b[] = {3, 5, 7};
    int c[] = {3, 5, 7, 9};
    int d[] = {3, 5, 7, 9, 11};
    
    cout << sum(2, a) << '\n';
    cout << sum(3, b) << '\n';
    cout << sum(4, c) << '\n';
    cout << sum(5, d) << '\n';
    
    return 0;
}
