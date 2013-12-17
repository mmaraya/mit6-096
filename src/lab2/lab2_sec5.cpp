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
#include <cmath>
using namespace std;

static int COUNT = 5000000; // number of dart throws
static double RADIUS = 1; // radius of circle

//
// Check if throw is inside circle
//
bool insideCircle(double x, double y, double radius)
{
    // compute distance using Euclidean formula (d^2 = x^2 + y^2)
    double distance = sqrt(x * x + y * y);
    
    // return true if distance is less than or equal to radius
    if (distance < radius) return true;
    
    return false;
}

//
// Calculate π
//
double calcuate(const int throws)
{
    // number of dart hits inside the circle
    int inside {0};
    
    // seed random number generator
    srand((int) time(NULL));
    
    // perform a Monte Carlo simulation
    for( int i = 0; i < throws; i++ )
    {
        // throw the dart
        double x =  rand() / (double) RAND_MAX;
        double y =  rand() / (double) RAND_MAX;
        
        // check if the dart landed in the circle
        if (insideCircle(x, y, RADIUS) == true) inside++;
    }
    
    // return the ratio of darts inside vs outside circle
    cout << "Total: " << throws << ", Inside: " << inside << '\n';
    return (double) inside * 4 / throws;
}

//
// 5.0 Calculate π using a Monte Carlo simulation
//
int main(int argc, const char *argv[])
{
    double result = calcuate(COUNT);
    cout << "π: " << result << '\n';
    return 0;
}
