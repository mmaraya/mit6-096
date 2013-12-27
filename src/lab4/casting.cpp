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

#include "casting.h"

// return the distance to another Point
double Point::distance(const Point &p) {
    double a = abs(p.getX() - getX());
    double b = abs(p.getY() - getY());
    return sqrt(a * a + b * b);
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
Polygon::Polygon(const Point pa[], const int length) : points(pa, length) {
    count++;
}

// Returns the number of sides of the Polygon.
int Polygon::getNumSides()
{
    return points.getSize();
}

// Allow constructing a Rectangle from two Points (the lower left coordinate and
// the upper right coordinate)

Point constructorPoints[4];
Point *updateConstructorPoints(const Point &p1, const Point &p2, const Point &p3,
                               const Point &p4 = Point(0,0)) {
    constructorPoints[0] = p1;
    constructorPoints[1] = p2;
    constructorPoints[2] = p3;
    constructorPoints[3] = p4;
    return constructorPoints;
}

// Allow constructing a Rectangle from two Points (the lower left coordinate and the
// upper right coordinate)
Rectangle::Rectangle(const Point &ll, const Point &ur) :
Polygon{updateConstructorPoints(ll, Point(ll.getX(), ur.getY()), Point(ur.getX(), ll.getY()), ur), 4} {}

// Allow constructing a Rectangle from four ints
Rectangle::Rectangle(const int a, const int b, const int c, const int d) :
Polygon{updateConstructorPoints(Point(a,b), Point(a,d), Point(c,b), Point(c,d)), 4} {}

// Override the Polygon::area’s behavior such that the rectangle’s area is calculated
// by multiplying its length by its width, but still return the area as a double.
double Rectangle::area() {
    if (points.getSize() != 4) return 0;
    
    // find the lower left and upper right points
    Point ll = points.getPoints()[0], ur = points.getPoints()[0];
    for (int i = 0; i < points.getSize(); i++) {
        Point test = points.getPoints()[i];
        if (test.getX() < ll.getX() || test.getY() < ll.getY())
            ll = test;
        if (test.getY() > ur.getY() || test.getX() > ur.getX())
            ur = test;
    }
    
    // compute and return area
    int length = abs(ur.getX() - ll.getX());
    int height = abs(ur.getY() - ll.getY());
    return (double) length * height / 2;
}

// Construct a Triangle from three Points
Triangle::Triangle(const Point &a, const Point &b, const Point &c) :
Polygon(updateConstructorPoints(a, b, c), 3) {}

// Override the area function such that it calculates the area using Heron’s formula
double Triangle::area() {
    
    Point p1 = getPoints().getPoints()[0];
    Point p2 = getPoints().getPoints()[1];
    Point p3 = getPoints().getPoints()[2];
    
    // get lengths of the sides
    double a = p1.distance(p2);
    double b = p2.distance(p3);
    double c = p3.distance(p1);
    
    // compute s
    double s = (double) (a + b + c) / 2;
    
    // compute area using Heron's formula
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Write a small function with signature void printAttributes(Polygon *) that prints
// the area of the polygon and prints the (x, y) coordinates of all of its points.
void printAttributes(Polygon *poly) {
    cout << "PointArray: " << poly->getPoints() << ", Area: " << poly->area() << '\n';
}

int main(const int argc, const char *argv[]) {
    Rectangle rectangle = Rectangle(Point(1,1), Point(2,3));
    Rectangle *rect = &rectangle;

    // Write a line of code showing how you would cast rect to a Triangle * without
    // checking for type correctness (i.e., without checking whether it actually points
    // to a Triangle). Do not use C-style casts.
    
    // Triangle *triangle1 = static_cast<Triangle*>(rect); // this results in a compile error
    
    // Now write a line of code that does the same thing, but checks for type correctness
    // and throws an exception or returns a null pointer if rect does not actually point
    // to a Triangle.

    Triangle *triangle = dynamic_cast<Triangle*>(rect);
    
    return 0;
}