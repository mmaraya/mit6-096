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

#include "geometry.h"

void lab3_sec3()
{
    Point p1 = Point();
    Point p2 = Point(1, 2);
    
    cout << p1 << '\n' << p2 << '\n';
    
    p1.setX(3);
    p1.setY(4);
    
    cout << p1 << '\n';
    
    p2.setX(5);
    p2.setY(6);
    
    cout << p2 << '\n';
    
    return;
}

void lab3_sec4()
{
    PointArray emptyArray = PointArray();
    cout << "Empty PointAray: " << emptyArray << '\n';
    
    Point p1 = Point(1, 2);
    Point one[1] = {p1};
    PointArray singleArray = PointArray(one, 1);
    cout << "Singe-element PointArray: " << singleArray << '\n';
    
    Point p2 = Point(3, 4);
    Point two[2] = {p1, p2};
    PointArray doubleArray = PointArray(two, 2);
    cout << "Double-element PointArray: " << doubleArray << '\n';
    
    PointArray copy = doubleArray;
    cout << "Copied PointArray: " << copy << '\n';
    
    Point p3 = Point(5, 6);
    copy.push_back(p3);
    cout << "Added Point: " << copy << '\n';

    Point p4 = Point(7, 8);
    copy.insert(1, p4);
    cout << "Inserted at 1: " << copy << '\n';
    
    copy.remove(1);
    cout << "Removed 1: " << copy << '\n';
    
    copy.clear();
    cout << "Cleared: " << copy << '\n';
    
    PointArray bigArray = doubleArray;
    bigArray.push_back(p3);
    bigArray.push_back(p4);
    bigArray.push_back(Point(9, 10));
    bigArray.push_back(Point(11, 12));
    cout << "Big Array: " << bigArray << '\n';
    
    Point *subset = bigArray.get(3);
    cout << "Subset: " << *subset << '\n';
    
    return;
}

int main(int argc, const char *argv[])
{
    lab3_sec3();
    lab3_sec4();
    return 0;
}