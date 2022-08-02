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
Scalar dot(const Vector3& a, const Vector3& b);


class Vector3{
public:
    Scalar x,y,z; // the three coordinates (as fields)

    // constuctor
    Vector3(Scalar _x, Scalar _y, Scalar _z):x(_x),y(_y),z(_z){ }

    // empty constructor
    Vector3():x(0.0),y(0.0),z(0.0){ }

    void print() const {
        std::cout << "(" << x << "," << y << "," << z << ") ";
    }

    // vector sum
    Vector3 operator + ( const Vector3 & b ) const {
        return Vector3( x+b.x , y+b.y , z+b.z );
    }

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
        return sqrt( squaredNorm() );
    }

    /*
    // l'operatore == lo usiamo per l'egualianza SECCA
    // altrimenti, potremmo implementarlo cosi'
    bool operator == ( const Vector3 & b ) const {
        return (*this - b).isZero();
    }
    */


};

Vector3 operator * ( Scalar k, const Vector3 &a ){
    return a*k;
}

Scalar dot(const Vector3& a, const Vector3& b){
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

bool areEqual( const Vector3& a, const Vector3& b ){
    return (a-b).isZero();
}

bool areEqual( Scalar a, Scalar b ){
    return abs(a-b)<EPSILON;
}



} // end of namespace VgMath

using namespace VgMath;

// testing basic vector operators
void unitTestVectorOperators(){
    Vector3 v(3.0,3.5,5.0);
    Vector3 w(1.0,2.5,4.0);
    Vector3 r(3.5,1.0,3.0);

    assert( areEqual( v+w , w+v ) );
    assert( areEqual( v+v , 2*v ) );
    assert( areEqual( dot(r,v+w) , dot(r,v)+dot(r,w) ) );
    assert( areEqual( v-w , -1*w + v ) );
    assert( areEqual( dot(r,v) , dot(v,r) ) );
}

int main()
{

    unitTestVectorOperators();

    return 0;
}
