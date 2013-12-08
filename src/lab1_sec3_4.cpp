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
// 3.4.1 Ternary operator
// Write a program that loops indefinitely. In each iteration of the loop, read in an
// integer N (declared as an int) that is inputted by a user, output N5 if N is
// nonnegative and divisible by 5, and -1 otherwise. Use the ternary operator (?:) to
// accomplish this. (Hint: the modulus operator may be useful.)
//
void lab1_sec3_4_1() {
    // infinite loop
    do {
        int input;
        cout << "Enter an integer: ";
        cin >> input;
        cout << ((input > 0 && input % 5 == 0) ? input / 5 : -1) << '\n';
    } while (true);
}

//
// 3.4.2 continue
// Modify the code from 3.4.1 so that if the condition fails, nothing is printed. Use an
// if and a continue command (instead of the ternary operator) to accomplish this.
//
void lab1_sec3_4_2() {
    // infinite loop
    do {
        int input;
        cout << "Enter an integer: ";
        cin >> input;
        if ((input < 0 || input % 5 != 0)) {
            continue;
        }
        cout << (input / 5) << '\n';
    } while (true);
}

//
// 3.4.3 break
// Modify the code from 3.4.2 to let the user break out of the loop by entering -1
// or any negative number. Before the program exits, output the string “Goodbye!”.
//
void lab1_sec3_4_3() {
    // infinite loop
    do {
        int input;
        cout << "Enter an integer: ";
        cin >> input;
        if (input == -1) {
            cout << "Goodbye!\n";
            break;
        }
        if ((input < 0 || input % 5 != 0)) {
            continue;
        }

        cout << (input / 5) << '\n';
    } while (true);
}

//
// Execute all functions in Lab 1, Sec 3.4
// The first two functions are commented out since they require a break to exit
//
int main(int argc, const char *argv[])
{
    //lab1_sec3_4_1();
    //lab1_sec3_4_2();
    lab1_sec3_4_3();
    return 0;
}
