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

void section3_2()
{
    int index = 0;
    
    // request N number of integers from user
    cout << "Enter number of integers: ";
    cin >> index;
    int array[index];
    for (int i = 0; i < index; i++) {
        cin >> array[i];
    }
    
    // display what the user entered
    cout << "You entered " << index << " integer(s): ";
    for (int i = 0; i < index; i++) {
        cout << array[i] << (index == i+1 ? "\n" : ", ");
    }
    
    // compute mean, max, min and range
    int sum = 0;
    int minimum = array[0], maximum = array[0];
    
    for (int i = 0; i < index; i++) {
        // compute sum to determine mean
        sum += array[i];
        // compute minimum
        if (array[i] < minimum) {
            minimum = array[i];
        }
        // compute maximum
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }
    
    double mean = (double) sum / index;
    int range = maximum - minimum;
    
    // display results
    cout << "Mean: " << mean << '\n';
    cout << "Max: " << maximum << '\n';
    cout << "Min: " << minimum << '\n';
    cout << "Range: " << range << '\n';
    
    return;
    
}
