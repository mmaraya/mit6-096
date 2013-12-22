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
    Point(int x = 0, int y = 0) : x{x}, y{y} {}
    
    // getter for x
    const int getX() const { return x; }
    
    // getter for y
    const int getY() const { return y; }
    
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

class PointArray {

private:
    
    Point * points;
    int size;
    void resize(int n);
    
public:
    
    PointArray();
    PointArray(const Point points[], const int size);
    PointArray(const PointArray &pv);
    ~PointArray();
    
    int getSize() const { return size; }
    Point * getPoints() const { return points; }

    void clear();
    void push_back(const Point &p);
    void insert(const int position, const Point &p);
    void remove(const int pos);
    Point * get(const int position);
    const Point * get(const int position) const;
};

// overload the ostream << operator for PointArray
ostream &operator<<(ostream &out, const PointArray &points)
{
    Point *p = points.getPoints();
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
    
    Polygon(const PointArray &pa);
    Polygon(const Point pa[], const int length);
    ~Polygon() { count--; }
    const PointArray getPointArray() const { return points; }
    const int getCount() const { return count; }
    
};

// overload the ostream << operator for Polygon
ostream &operator<<(ostream &out, const Polygon &poly)
{
    out << poly.getPointArray() << '(' << poly.getCount() << ')';
    return out;
}
