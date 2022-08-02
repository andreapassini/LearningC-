/* file "vector3.h" */

#pragma once

#include <iostream>
#include <cmath>
#include <assert.h>

using namespace std;

namespace VgMath{

typedef double Scalar;

const Scalar EPSILON = 1e-10;
const Scalar EPSILON2 = EPSILON*EPSILON;

// forward declarations
class Vector3;
class Versor3;
Scalar dot(const Vector3& a, const Vector3& b);


class Vector3{
public:
    Scalar x,y,z; // the three coordinates (as fields)

    // constuctor
    Vector3(Scalar _x, Scalar _y, Scalar _z):x(_x),y(_y),z(_z){ }

    // empty constructor
    Vector3():x(0.0),y(0.0),z(0.0){ }

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
        std::cout << "(" << x << "," << y << "," << z << ") ";
    }

    // vector sum
    Vector3 operator + ( const Vector3 & b ) const {
        return Vector3( x+b.x , y+b.y , z+b.z );
    }

    // the UNITARY plus
    Vector3 operator + () const { return *this; }

    // the BINARY minus
    Vector3 operator - ( const Vector3 & b ) const {
        return Vector3( x-b.x , y-b.y , z-b.z );
    }

    // the UNARY minus
    Vector3 operator - () const {
        return Vector3( -x, -y, -z );
    }

    Vector3 operator * ( Scalar k ) const {
        return Vector3( k*x , k*y , k*z );
    }

    Vector3 operator / ( Scalar k ) const {
        return Vector3( x/k , y/k , z/k );
    }

    // versioni "in place":
    void operator += ( const Vector3 & b ) { x+=b.x; y+=b.y; z+=b.z; }
    void operator -= ( const Vector3 & b ) { x-=b.x; y-=b.y; z-=b.z; }
    void operator *= ( Scalar k ) { x*=k; y*=k; z*=k; }
    void operator /= ( Scalar k ) { x/=k; y/=k; z/=k; }


    bool isZero() const{
        return squaredNorm() < EPSILON2;
    }

    Scalar squaredNorm() const {
        return dot( *this, *this );
        // OR:
        // return x*x + y*y + z*z ;
    }

    Scalar norm() const {
        return std::sqrt( squaredNorm() );
    }

    Versor3 normalized() const;

    /*
    // l'operatore == lo usiamo per l'egualianza SECCA
    // altrimenti, potremmo implementarlo cosi'
    bool operator == ( const Vector3 & b ) const {
        return (*this - b).isZero();
    }
    */

}; // end of class Vector3

inline Vector3 operator * ( Scalar k, const Vector3 &a ){
    return a*k;
}

inline Scalar dot(const Vector3& a, const Vector3& b){
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

inline Vector3 cross(const Vector3& a, const Vector3& b){
    return Vector3(
       a.y*b.z - b.y*a.z, // the X of the cross
       a.z*b.x - b.z*a.x, // the Y of the cross
       a.x*b.y - b.x*a.y  // the Z of the cross
    );
}

inline Scalar rad2deg(Scalar k){
    return k/(M_PI)*180;
}

inline Scalar deg2rad(Scalar k){
    return k*(M_PI)/180;
}

inline Vector3 mix(Vector3 a, Vector3 b, Scalar t){
    return a*(1-t) + b*t;
}

inline Scalar mix(Scalar a, Scalar b, Scalar t){
    return a*(1-t) + b*t;
}



inline Scalar angleBetween( const Vector3 &a , const Vector3 &b ) {
    Scalar abSinAlpha = cross(a,b).norm(); // ab is a.norm() * b.norm()
    Scalar abCosAlpha = dot(a,b);
    return rad2deg(atan2(abSinAlpha,abCosAlpha));
}



inline bool areEqual( const Vector3& a, const Vector3& b ){
    return (a-b).isZero();
}

inline bool areEqual( Scalar a, Scalar b ){
    return abs(a-b)<EPSILON;
}




} // end of namespace VgMath
