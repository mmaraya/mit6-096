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

const int LENGTH = 3;
const int WIDTH = 4;

//
// 6.1
// Write a function printArray to print the contents of an integer array with the
// string ", " between elements (but not after the last element). Your function should
// return nothing.
//
void printArray(const int list[], const int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << list[i];
        if (i < length - 1) {
            cout << ", ";
        }
    }
    cout << '\n';
}

//
// 6.2
// Write a reverse function that takes an integer array and its length as arguments.
// Your function should reverse the contents of the array, leaving the reversed values
// in the original array, and return nothing.
//
void reverse(int list[], const int length)
{
    // swap the numbers at each end of the list and work towards the middle
    for (int i = 0; i < length / 2; i++)
    {
        int temp = list[i];
        list[i] = list[length - 1 - i];
        list[length - 1 - i] = temp;
    }
    return;
}

//
// 6.3
// Assume the existence of two constants WIDTH and LENGTH. Write a function with the
// following signature:
// void transpose(const int input[][LENGTH], int output[][WIDTH]);
//
// Your function should transpose the WIDTH × LENGTH matrix in input, placing the
// LENGTH × WIDTH transposed matrix into output.
// (See http://en.wikipedia.org/wiki/Transpose#Examples for examples of what it means to
// transpose a matrix.)
//
void transpose(const int input[][LENGTH], int output[][WIDTH])
{
    for (int i = 0; i < LENGTH; i++)
        for (int j = 0; j < WIDTH; j++)
            output[i][j] = input[j][i];
    return;
}

//
// 6.5
// Rewrite your function from part 2 to use pointer-offset notation instead of
// array-subscript notation.
//
void reverse2(int *list, const int length)
{
    // swap the numbers at each end of the list and work towards the middle
    for (int i = 0; i < length / 2; i++)
    {
        int temp = *(list +i);
        *(list +i) = *(list + length - 1 - i);
        *(list + length - 1 - i) = temp;
    }
    return;
}

//
// 6 Array Operations
//
int main(int argc, const char *argv[])
{
    // 6.1
    int list1[] {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "6.1: ";
    printArray(list1, 9);

    // 6.2
    reverse(list1, 9);
    cout << "6.2: ";
    printArray(list1, 9);
    
    // 6.3
    int list2[WIDTH][LENGTH] = { {1, 2, 3} , {4, 5, 6} , {7, 8, 9} , {10, 11, 12} };
    int list3[LENGTH][WIDTH];
    transpose(list2, list3);
 
    cout << "6.3 Original Matrix:\n";
    for (int i = 0; i < WIDTH; i++) {
        printArray(list2[i], LENGTH);
    }

    cout << "6.3 Transposed Matrix:\n";
    for (int i = 0; i < LENGTH; i++) {
        printArray(list3[i], WIDTH);
    }
    
    // 6.4
    //
    // Q: What would happen if, instead of having output be an “out argument,” we simply
    // declared a new array within transpose and returned that array?
    //
    // A: The new array within transpose() would be dereferenced after transpose() returns
    //
    
    // 6.5
    cout << "6.5: ";
    reverse2(list1, 9);
    printArray(list1, 9);
    
    return 0;
}
