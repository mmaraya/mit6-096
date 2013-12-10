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
// 4.6
// Now rewrite your function from 4.5 to use recursion instead of a loop. The
// function signature should not change. Thinking about pointer arithmetic may help you.
//

int sum(const int elements, const int *array)
{
    // stop recursion if there are no elements left
    int result = 0;
    if (elements == 0) {
        return 0;
    }
    
    // add the last element and recursively process the elements before the last element
    result = array[elements-1] + sum(elements-1, array);
    
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
