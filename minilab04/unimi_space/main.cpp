/* file "main.cpp" */

#include <assert.h>

#include "vector3.h"
#include "versor3.h"
#include "point3.h"
#include "mat3.h"

using namespace VgMath;

// testing basic vector operators
void unitTestVectorOperators(){
    Vector3 v(3.0,3.5,5.0);
    Vector3 w(1.0,2.5,4.0);
    Vector3 r(3.5,1.0,3.0);

    assert( areEqual( v+w , w+v ) ); // vector sum is communtative
    assert( areEqual( v+v , 2*v ) );
    assert( areEqual( dot(r,v+w) , dot(r,v)+dot(r,w) ) ); // dot product distributes with vector sum
    assert( areEqual( v-w , -1*w + v ) );
    assert( areEqual( dot(r,v) , dot(v,r) ) ); // dot product is commutative

    assert( areEqual( cross(v,w) , - cross(w,v) ) ); // cross is ANTI commutative
    assert( areEqual( dot( cross(v,w) , v ) , 0.0 ) ); // cross(v,w) is ortogonal to v
    assert( areEqual( dot( cross(v,w) , w ) , 0.0 ) ); // cross(v,w) is ortogonal to w

    Vector3 a = Vector3(3,0,0);
    Vector3 b = Vector3(5,5,0);
    assert( areEqual( angleBetween(a,b),45) );

    b[0] = -b[0];
    assert( areEqual( angleBetween(a,b),135) );

}

void test(){
    Versor3 ppp = Versor3::up();
    Point3 qqq = Point3::origin();
    Versor3 aaa = +ppp;

    int x = 4;
    int y = +x;
}

void unitTestMatrix(){
    Mat3 M;
    M.setRowMajor( -1,+2,-3,
                   +2,+3,+1,
                   -2,+2,-1 );

    Vector3 v(10,40,-3);

    assert( areEqual( M*v , M%v ) ); // testing that the two alternative ways to write a product are equivalent


    Mat3 N;
    N.setColumnMajor( 5,6,1 ,
                      2,-1,5,
                      8,-5,-9);

    assert( areEqual(  (M*N)*v , M*(N*v) ) ); // testing if products are associative

    Mat3 I = Mat3::identity();

    assert( areEqual( M.inverse() * (M * v)  , v ) ); // testing that the two alternative ways to write a product are equivalent
    assert( areEqual( M.inverse() * M , I ) ); // testing that the two alternative ways to write a product are equivalent
    assert( areEqual( M * M.inverse() , I ) ); // testing that the two alternative ways to write a product are equivalent


    Mat3 Mt = M;
    Mt.transpose();
    assert( areEqual( M.transposed(), Mt )); // testing if the in-place method is the same as the out-of-place

}

int main()
{

    unitTestVectorOperators();
    unitTestMatrix();

    Versor3 mioVersore = Versor3::up(); // legale: mi findo della classe Versor3 per farmi dare una cosa unitario
    // Versor3 unAltroMioVersore = Versor3(1,1,3); // ILLEGALE

    Versor3 mioVersore2 = Vector3(1,1,2).normalized();


    return 0;
}
