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
// 4.1
// Write a single sum function that returns the sum of two integers. Also write the
// equivalent function for taking the sum of two doubles.
//

int sum(const int a, const int b)
{
    return a + b;
}

double sum(const double a, const double b)
{
    return a + b;
}

int main(int argc, const char *argv[])
{
    cout << sum(1, 3) << '\n';
    cout << sum(1.5, 2.3) << '\n';
    
    return 0;
}

//
// 4.2
// Explain why, given your functions from part 1, sum(1, 10.0) is a syntax error.
// (Hint: Think about promotion and demotion – the conversion of arguments between types
// in a function call. Remember that the compiler converts between numerical types for
// you if necessary.) [1 point]
//

//
// sum(1, 10.0) is a call to a function with signature sum(int, double) and we have not
// defined a function with this signature
//
