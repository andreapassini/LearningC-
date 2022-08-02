#include <iostream>
using namespace std;

typedef double Scalar;

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

    // add another vector to this one, return the result
    Vector3 sum( const Vector3 & b ) const {
        return Vector3( x+b.x , y+b.y , z+b.z );
    }

    // equivalent of the above
    Vector3 operator + ( const Vector3 & b ) const {
        return Vector3( x+b.x , y+b.y , z+b.z );
    }

};


// vector sum again, but this time as a global function
Vector3 sum( const Vector3 &  a, const Vector3 & b ) {
    return Vector3( a.x+b.x , a.y+b.y , a.z+b.z );
}



int main()
{
    Vector3 p;
    p.x = 1.0;
    p.y = 2.0;
    p.z = 3.0;

    Vector3 q(1.0,2.0,3.0);
    p.print();
    cout << " + " ;
    q.print();
    cout << " = " ;
    //Vector3 r = somma( p , q );
    Vector3 r;

    // 4 equialent commands to sum p and q:
    r = sum( p , q );       // using the global function
    r = p.sum( q );         // using the method
    r = p.operator+ ( q );  // using the overloaded operator
    r = p + q;              // same as above! We will use this one!

    r.print();

    return 0;
}
