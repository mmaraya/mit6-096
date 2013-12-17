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
// 4.1 Writing the factorial program
// Here is the code for a factorial program. Copy it into your IDE and verify that it
// compiles.
//
void lab1_sec4_1()
{
    short number;
    cout << "Enter a number: ";
    cin >> number;
    if (number < 0) {
        cout << number << " is not a non-negative integer\n";
    } else {
        cout << "The factorial of " << number << " is ";
        unsigned int accumulator = 1;
        for(; number > 0; accumulator *= number--);
        cout << accumulator << ".\n";
    }
}

//
// 4.5 Rewriting Factorial II
// Since we know that only a small number of inputs produce valid outputs, we can
// alterna­tively hardcode the factorials of these inputs. Rewrite the program from the
// previous part (“Rewriting Factorial”) using a switch statement to demonstrate for inputs
// up to 10 how you would do this. (Of course, the code for inputs above 10 would basically
// be the same, but you do not need to go through the work of finding all those large
// factorials.)
//
int main(int argc, const char *argv[])
{
    short number;
    cout << "Enter a number: ";
    cin >> number;
    if (number < 0) {
        cout << number << " is not a non-negative integer\n";
        return 1;
    }
    unsigned int accumulator = 1;
    switch (number) {
        case 1:
            accumulator = 1;
            break;
        case 2:
            accumulator = 2;
            break;
        case 3:
            accumulator = 6;
            break;
        case 4:
            accumulator = 24;
            break;
        case 5:
            accumulator = 120;
            break;
        case 6:
            accumulator = 720;
            break;
        case 7:
            accumulator = 5040;
            break;
        case 8:
            accumulator = 40320;
            break;
        case 9:
            accumulator = 362880;
            break;
        case 10:
            accumulator = 3628800;
            break;
        default:
            for(int i = number; i > 0; accumulator *= i--);
    }

    cout << "The factorial of " << number << " is " << accumulator << ".\n";
    return 0;
}
