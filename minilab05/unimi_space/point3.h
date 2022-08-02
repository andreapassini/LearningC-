#pragma once
#include <assert.h>
#include <iostream>
#include "vector3.h"

namespace VgMath{

typedef double Scalar;

/* a 3D point, aka, a POSITION in 3D */

class Point3{
public:
    Scalar x,y,z; // the three coordinates (as fields)

    // constuctor
    Point3(Scalar _x, Scalar _y, Scalar _z):x(_x),y(_y),z(_z){ }

    // empty constructor: ORIGIN point
    Point3():x(0.0),y(0.0),z(0.0){ }

    static Point3 origin() { return Point3(); }

    // accessing the coordiantes as an array  READING THEM
    Scalar operator[] (int i) const {
        if (i==0) return x;
        if (i==1) return y;
        assert(i==2);
        return z;
    }

    // accessing the coords WRITING
    Scalar& operator[] (int i) {
        if (i==0) return x;
        if (i==1) return y;
        assert(i==2);
        return z;
    }


    void print() const {
        std::cout << "[" << x << "," << y << "," << z << "] ";  // [] for points (made-up convention)
    }

    // to scale a point means to bring it closer to (k<1), or farther from (k>1), the origin
    void scale( Scalar k ){
        x *= k;
        y *= k;
        z *= k;
    }

    // point - point = vector
    Vector3 operator - (const Point3 &b) const{
        return Vector3( x-b.x, y-b.y, z-b.z );
    }

    // point + vector = point
    Point3 operator + (const Vector3& v) const{
        return Point3( x+v.x , y+v.y, z+v.z );
    }

    bool isOrigin() const{
        return areEqual(x,0) && areEqual(y,0) && areEqual(z,0);
    }

}; // end of class Point3


inline Point3 mix(Point3 a, Point3 b, Scalar t){
    return a + (b-a)*t;
}

inline bool areEqual( const Point3& a, const Point3& b ){
    return areEqual(a.x,b.x) && areEqual(a.y,b.y) && areEqual(a.z,b.z);
}

// point + vector is commutative
inline Point3 operator + (const Vector3 &v, const Point3 &p){
    return p+v;
}



} // end of namespace

