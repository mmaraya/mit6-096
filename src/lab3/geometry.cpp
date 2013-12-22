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

// Implement the default constructor (a constructor with no arguments) with
// the following signature. It should create an array with size 0.
PointArray::PointArray()
{
    size = 0;
    points = new Point[size];
    clog << "PointArray::PointArray(): allocated " << points << '\n';
}

// Implement a constructor that takes a Point array called points and an int
// called size as its arguments. It should initialize a PointArray with the
// specified size, copying the values from points. You will need to dynamically
// allocate the PointArray’s internal array to the specified size.
PointArray::PointArray(const Point pa[], const int size) : size{size}
{
    points = new Point[size];
    for (int i = 0; i < size; i++)
    {
        points[i] = pa[i];
    }
}

// Finally, implement a constructor that creates a copy of a given PointArray
// (a copy constructor ). Make sure that the two PointArrays do not end up using the
// same memory for their internal arrays. Also make sure that the contents of the
// original array are copied, as well.
PointArray::PointArray(const PointArray &pv) : size{pv.getSize()}
{
    points = new Point[size];
    for(int i = 0; i < size; i++) {
        points[i] = pv.getPoints()[i];
    }
}

// Define a destructor that deletes the internal array of the PointArray.
PointArray::~PointArray()
{
    delete[] points;
}

// write a member function PointArray::resize(int n) that allocates a new array
// of size n, copies the first min(previous array size, n) existing elements into
// it, and deallocates the old array.
void PointArray::resize(int n)
{
    Point * newPoints = new Point[n];
    
    // copy the first min(previous array size, n) existing elements
    for (int i = 0; i < (size < n ? size : n); i++)
        newPoints[i] = points[i];
    
    // deallocate old array
    delete[] points;
    
    // set new attributes
    points = newPoints;
    size = n;
}

// Remove everything from the array and sets its size to 0
void PointArray::clear()
{
    resize(0);
}

// Add a Point to the end of the array
void PointArray::push_back(const Point &p)
{
    resize(size + 1);
    points[size -1] = p;
}

// Insert a Point at some arbitrary position (subscript) of the array,
// shifting the elements past position to the right
void PointArray::insert(const int position, const Point &p)
{
    // increase the size of our array
    resize(size + 1);
    
    // copy from the end of the array to insertion point
    for (int i = size - 1; i > position; i--)
        points[i] = points[i-1];
    
    // insert p
    points[position] = p;
}

// Remove the Point at some arbitrary position (subscript) of the array,
// shifting the remaining elements to the left
void PointArray::remove(const int pos)
{
    // shift elements from position onwards
    for (int i = pos; i < size - 2; i++)
        points[i] = points[i+1];
    
    // resize array
    resize(size - 1);
}

// Get a pointer to the element at some arbitrary position in the array,
// where positions start at 0 as with arrays
Point * PointArray::get(const int position)
{
    return points + position;
}

// Get a pointer to the element at some arbitrary position in the array,
// where positions start at 0 as with arrays
const Point * PointArray::get(const int position) const
{
    return points + position;
}

void lab3_sec4()
{
    Point p1 = Point(1, 2);
    Point p2 = Point(3, 4);
    Point p3 = Point(5, 6);
    Point p4 = Point(7, 8);
    
    PointArray emptyArray = PointArray();
    cout << "Empty PointAray: " << emptyArray << '\n';
    
    Point one[1] = {p1};
    PointArray singleArray = PointArray(one, 1);
    cout << "Singe-element PointArray: " << singleArray << '\n';
    
    Point two[2] = {p1, p2};
    PointArray doubleArray = PointArray(two, 2);
    cout << "Double-element PointArray: " << doubleArray << '\n';
    
    PointArray copy = doubleArray;
    cout << "Copied PointArray: " << copy << '\n';
    
    copy.push_back(p3);
    cout << "Added Point: " << copy << '\n';
    
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

// static data members must be explicity defined in exactly one compilation unit

int Polygon::count = 0;

// Implement a constructor that creates a polygon using the points in an existing
// PointArray that is passed as an argument.  You should make sure your constructor
// avoids the unnecessary work of copying the entire existing PointArray each time
// it is called.
Polygon::Polygon(const PointArray &pa) : points{pa} {
    count++;
}

// Implement a constructor that creates a Polygon from two arguments: an array of
// Points and the length of that array. Use member initializer syntax to initialize
// the internal PointArray object of the Polygon, passing the Polygon constructor
// arguments to the PointArray con­structor. You should need just one line of code in
// the actual constructor body.
Polygon::Polygon(const Point pa[], const int length)
{
    points = PointArray(pa, length);;
    count++;
}

void lab3_sec5()
{
    Point p1[] = {Point(1,2), Point(3,4), Point(5,6), Point(7,8)};
    PointArray pa1 = PointArray(p1, 4);
    Polygon poly1 = Polygon(pa1);
    cout << "Polygon 1: " << poly1 << '\n';
    
    Point p2[] = {Point(10,20), Point(30,40), Point(50,60), Point(70,80)};
    PointArray pa2 = PointArray(p2, 4);
    Polygon poly2 = Polygon(pa2);
    cout << "Polygon 2: " << poly2 << '\n';
}

int main(const int argc, const char *argv[])
{
    // lab3_sec3();
    // lab3_sec4();
    lab3_sec5();
    return 0;
}