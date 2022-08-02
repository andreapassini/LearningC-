#include <iostream>
#include <cmath>
#include <assert.h>

#include "vector3.h"


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

int main()
{

    unitTestVectorOperators();

    return 0;
}
