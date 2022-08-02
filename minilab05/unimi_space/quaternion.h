#pragma once

#include "vector3.h"
#include "versor3.h"

namespace VgMath{
typedef double Scalar;

class Quaternion; // a forward declaration
inline Quaternion operator * (const Quaternion &a , const Quaternion &b);  // idem

class Quaternion{
public:
    Vector3 im;
    Scalar re;

    Quaternion(Scalar a, Scalar b, Scalar c, Scalar d):im(a,b,c),re(d) {}

    Quaternion():Quaternion(0,0,0,1){}

    Quaternion(Vector3 iii, Scalar rrr):im(iii),re(rrr){}

    void conjugate(){ im = -im; }

    Quaternion conjugated() const { return Quaternion( -im, re ); }

    Scalar squaredNorm() const { return im.squaredNorm() + re*re; }
    Scalar norm() const { return std::sqrt(squaredNorm()); }

    // aritmetic operators "OUT OF PLACE"
    Quaternion operator / (Scalar d) const { return Quaternion(im/d,re/d); }
    Quaternion operator * (Scalar d) const { return Quaternion(im*d,re*d); }

    // aritmetic operators "IN PLACE"
    void operator /= (Scalar d){ im/=d; re/=d;}
    void operator *= (Scalar d){ im*=d; re*=d;}
    void operator += (const Quaternion &q){ im+=q.im; re+=q.re; }
    void operator -= (const Quaternion &q){ im-=q.im; re-=q.re; }

    void invert() {
        conjugate();
        operator /= ( squaredNorm() );
    }

    Quaternion inverse() const{
        return conjugated() / squaredNorm();
    }


    // apply this quaternion as a rotation to a vector
    // q.apply(v) = q' * v * q
    Vector3 apply(const Vector3 &v){
        // TODO: optimize! exploiting the 0 of the real part
        Quaternion res = this->conjugated()
                         *
                         Quaternion(v,0) // quaternion that represents a vector v
                         *
                         (*this);
        assert( areEqual( res.re , 0 ) );
        return res.im;
    }

    static Quaternion angleAxis(Scalar angleDeg, Versor3 axis){
        Scalar angleRad = deg2rad(angleDeg);
        return Quaternion(
            std::sin( angleRad / 2 ) * axis,
            std::cos( angleRad / 2 )
        );
    }


};


inline Quaternion operator * (const Quaternion &a , const Quaternion &b) {
    return Quaternion(
       a.re*b.im + a.im*b.re + cross(a.im,b.im),  // imaginary part
       a.re*b.re - dot(a.im,b.im) // real part
    );
}


}
