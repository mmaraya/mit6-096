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
#include <vector>
using namespace std;

template <class T> class Stack;
template<class T> Stack<T> operator+(const Stack<T> &s1, const Stack<T> &s2);

// Using templates, implement a Stack class that can be used to store items of any type.
template <class T>
class Stack {

private:
    friend Stack<T> operator+<>(const Stack<T> &s1, const Stack<T> &s2);
    vector<T> items;
    
public:
    
    // You do not need to implement any constructors or destructors; the default
    // constructor should be sufficient, and you will not need to use new.
    Stack() {};
    
    // bool Stack::empty() – returns whether the stack is empty
    bool empty() {
        return items.empty();
    }

    // void Stack::push(const T &item) – adds item to the stack
    void push(const T &item) {
        items.push_back(item);
    }

    // T &Stack::top() – returns a reference to the most-recently-added item
    T& top() {
        return items.back();
    }
    
    // void Stack::pop() – removes the most-recently-added item from the stack
    void pop() {
        items.pop_back();
    }
    
};

// Make a friend function that implements a + operator for Stacks.
template<class T>
Stack<T> operator+(const Stack<T> &s1, const Stack<T> &s2) {
    Stack<T> result = s1;
    for(int i = 0; i < s2.items.size(); ++i) {
        result.items.push_back(s2.items[i]);
    }
    return result;
}



