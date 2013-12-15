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

const char NULL_CHAR = '\x0';

//
// 7.1
//
// Write a function that returns the length of a string (char *), excluding the
// final NULL character. It should not use any standard-library functions. You may
// use arithmetic and dereference operators, but not the indexing operator ([]).
//
int stringLength(const char *string)
{
    int count = 0;
    
    char test = *string;
    while (test != NULL_CHAR)
    {
        count++;
        test = *(string + count);
    }
    
    return count;
}

//
// 7.2
//
// Write a function that swaps two integer values using call-by-reference.
//
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;

    return;
}

//
// 7.3
//
// Rewrite your function from part 2 to use pointers instead of references.
//
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}

//
// 7.4
//
// Write a function similar to the one in part 3, but instead of swapping two values,
// it swaps two pointers to point to each other’s values.
//
void swap(int **ptr1, int **ptr2)
{
    int *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    
    return;
}

//
// 7.5
//
void lab2_sec7_5() {
    
    char *oddOrEven = (char *) "Never odd or even";
    
    // Create a pointer to a char value named nthCharPtr pointing to the 6th character
    // of oddOrEven (remember that the first item has index 0). Use the indexing operator.
    char *nthCharPtr = &oddOrEven[5];
    
    // Using pointer arithmetic, update nthCharPtr to point to the 4th character in oddOrEven.
    nthCharPtr = nthCharPtr - 2;
    
    // Print the value currently pointed to by nthCharPtr.
    cout << "nthCharPtr: " << nthCharPtr << '\n';
    
    // Create a new pointer to a pointer (a char **) named pointerPtr that points to nthCharPtr.
    char **pointerPtr = &nthCharPtr;
    
    // Print the value stored in pointerPtr.
    cout << "pointerPtr: " << pointerPtr << '\n';
    
    // Using pointerPtr, print the value pointed to by nthCharPtr.
    cout << "*pointerPtr: " << *pointerPtr << '\n';

    // Update nthCharPtr to point to the next character in oddOrEven (i.e. one character
    // past the location it currently points to).
    nthCharPtr = nthCharPtr + 1;
    
    // Using pointer arithmetic, print out how far away from the character currently pointed
    // to by nthCharPtr is from the start of the string.
    cout << nthCharPtr - oddOrEven << '\n';
    
    return;
}

//
// 7 Pointers and Strings
//
int main(const int argc, const char *argv[])
{
    int a = 12, b = 73;

    // 7.1
    char *test = (char *) "7.1 This is a test!";
    cout << test << " (" << stringLength(test) << ")\n";
    
    // 7.2
    int &ra = a, &rb = b;
    swap(ra, rb);
    cout << "7.2 a: " << a << " b: " << b << '\n';
    
    // 7.3
    swap(&a, &b);
    cout << "7.3 a: " << a << " b: " << b << '\n';
    
    // 7.4
    int x = 5, y = 6;
    int *ptr1 = &x, *ptr2 = &y;
    swap(&ptr1, &ptr2);
    cout << "7.4 " << *ptr1 << ' ' << *ptr2 << '\n'; // Prints "6 5"
    
    // 7.5
    lab2_sec7_5();
    
    return 0;
}