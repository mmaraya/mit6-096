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

#include "stack.h"

int main(const int argc, const char* argv[]) {
    
    Stack<int> stack;
    
    // section 4.1
    if (stack.empty()) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack is not empty\n";
    }

    stack.push(1);
    cout << stack.top() << " added to stack\n";
    if (stack.empty()) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack is not empty\n";
    }
    
    stack.pop();
    if (stack.empty()) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack is not empty\n";
    }
    
    // section 4.2
    Stack<int> a, b;
    a.push(1);
    a.push(2);
    b.push(3);
    b.push(4);
    Stack<int> c = a + b;

    while (!c.empty()) {
        cout << c.top() << ' ';
        c.pop();
    }
    
    return 0;
}