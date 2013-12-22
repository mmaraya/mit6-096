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

class Point
{
private:

    int x, y;
    
public:
    
    // default constructor
    Point(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    
    // getter for x
    int getX() const { return x; }
    
    // getter for y
    int getY() const { return y; }
    
    // setter for x
    void setX(const int x) { this->x = x; }
    
    // setter for y
    void setY(const int y) { this->y = y; }
    
};

// overload the ostream << operator for Point
ostream &operator<<(ostream &out, const Point &p)
{
    out << '(' << p.getX() << ',' << p.getY() << ')';
    return out;
}

class PointArray
{
private:
    
    Point * points; // pointer to the start of an array of Points
    int size; // size of the array
    
    // write a member function PointArray::resize(int n) that allocates a new array
    // of size n, copies the first min(previous array size, n) existing elements into
    // it, and deallocates the old array.
    void resize(int n)
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
        
        return;
    }

public:
    
    // Implement the default constructor (a constructor with no arguments) with
    // the following signature. It should create an array with size 0.
    PointArray()
    {
        size = 0;
        points = new Point[size];
    }
    
    // Implement a constructor that takes a Point array called points and an int
    // called size as its arguments. It should initialize a PointArray with the
    // specified size, copying the values from points. You will need to dynamically
    // allocate the PointArray’s internal array to the specified size.
    PointArray(const Point points[], const int size)
    {
        this->size = size;
        this->points = new Point[size];
        for (int i = 0; i < size; i++)
        {
            this->points[i] = points[i];
        }
    }
    
    // Finally, implement a constructor that creates a copy of a given PointArray
    // (a copy constructor ). Make sure that the two PointArrays do not end up using the
    // same memory for their internal arrays. Also make sure that the contents of the
    // original array are copied, as well.
    PointArray(const PointArray& pv)
    {
        size = pv.getSize();
        points = new Point[size];
        for(int i = 0; i < size; i++)
        {
            points[i] = pv.getPoints()[i];
        }
    }
    
    // Define a destructor that deletes the internal array of the PointArray.
    ~PointArray()
    {
        delete[] points;
    }

    // getter for points
    Point * getPoints() const { return points; }
    
    // getter for size
    int getSize() const { return size; }

    // Add a Point to the end of the array
    void push_back(const Point &p)
    {
        resize(size + 1);
        points[size -1] = p;
        return;
    }
    
    // Insert a Point at some arbitrary position (subscript) of the array,
    // shifting the elements past position to the right
    void insert(const int position, const Point &p)
    {
        // increase the size of our array
        resize(size + 1);
        
        // copy from the end of the array to insertion point
        for (int i = size - 1; i > position; i--)
            points[i] = points[i-1];
        
        // insert p
        points[position] = p;
        
        return;
    }
    
    // Remove the Point at some arbitrary position (subscript) of the array,
    // shifting the remaining elements to the left
    void remove(const int pos)
    {
        // shift elements from position onwards
        for (int i = 0; i < size; i++)
            if (i >= pos)
                points[i] = points[i+1];
        
        // resize array
        resize(size - 1);
        
        return;
    }
    
    // Remove everything from the array and sets its size to 0
    void clear()
    {
        // set all elents to NULL
        for (int i = 0; i < size; i++)
            points[i] = NULL;
        
        // set size to 0
        size = 0;
        
        return;
    }
    
    // Get a pointer to the element at some arbitrary position in the array,
    // where positions start at 0 as with arrays
    const Point * get(const int position) const
    {
        return &points[position];
    }
    
    // Get a pointer to the element at some arbitrary position in the array,
    // where positions start at 0 as with arrays
    Point * get(const int position)
    {
        return &points[position];
    }
    
};

// overload the ostream << operator for PointArray
ostream &operator<<(ostream &out, const PointArray &points)
{
    Point *p = points.getPoints();
    out << '(' << p << ')' << ": ";
    out << '{';
    for (int i = 0; i < points.getSize(); i++)
    {
        out << *p++;
        if (i < points.getSize() - 1) {
            out << ',';
        }
    }
    out << '}';
    return out;
}

// In this section you will implement a class for a convex polygon called Polygon.
// A convex polygon is a simple polygon whose interior is a convex set; that is,
// if for every pair of points within the object, every point on the straight line
// segment that joins them is also within the object.
// Polygon will be an abstract class – that is, it will be a placeholder in the class
// hierarchy, but only its subclasses may be instantiated. Polygon will be an immutable
// type – that is, once you create the Polygon, you will not be able to change it.
class Polygon
{
protected:
    
    PointArray points;
    static int count;
    
public:
    
    // Implement a constructor that creates a Polygon from two arguments: an array of
    // Points and the length of that array. Use member initializer syntax to initialize
    // the internal PointArray object of the Polygon, passing the Polygon constructor
    // arguments to the PointArray con­ structor. You should need just one line of code in
    // the actual constructor body.
    const Polygon(const Point pointArray[], const int length)
    {
        points = PointArray(pointArray, length);
        count++;
    }
    
    // Implement a constructor that creates a polygon using the points in an existing
    // PointArray that is passed as an argument. (For the purposes of this problem, you may
    // assume that the order of the points in the PointArray traces out a convex polygon.)
    // You should make sure your constructor avoids the unnecessary work of copying the
    // entire existing PointArray each time it is called.
    const Polygon(const PointArray points)
    {
        this->points = points;
        count++;
    }
    
};

