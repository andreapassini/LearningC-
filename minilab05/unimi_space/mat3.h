#pragma once

#include "vector3.h"


namespace VgMath{
typedef double Scalar;


class Mat3{
public:

    Vector3 col[3];

    Mat3( Vector3 a, Vector3 b, Vector3 c ){
        col[0]=a;
        col[1]=b;
        col[2]=c;
    }

    Mat3(){
        (*this) = identity();
    }

    static Mat3 identity(){
        return Mat3( Vector3(1,0,0) , Vector3(0,1,0) , Vector3(0,0,1) );
    }

    static Mat3 rotX( Scalar alpha ); // TODO
    static Mat3 rotY( Scalar alpha ); // TODO
    static Mat3 rotZ( Scalar alpha ); // TODO


    void setRowMajor(  Scalar a, Scalar b, Scalar c,
                       Scalar d, Scalar e, Scalar f,
                       Scalar g, Scalar h, Scalar i ) {
        col[0] = Vector3(a,d,g);
        col[1] = Vector3(b,e,h);
        col[2] = Vector3(c,f,i);
    }

    void setColumnMajor(  Scalar a, Scalar b, Scalar c,
                          Scalar d, Scalar e, Scalar f,
                          Scalar g, Scalar h, Scalar i ) {
        col[0] = Vector3(a,b,c);
        col[1] = Vector3(d,e,f);
        col[2] = Vector3(g,h,i);
    }

    Vector3 row( int i ) const {
        return Vector3( col[0][i], col[1][i], col[2][i] );
    }

    // matrix-vector multiplication
    Vector3 operator * (const Vector3 &p) const {
        // matrix-vector product as a LINEAR COMBINATION OF THE COLUMNS
        return p.x * col[0] + p.y * col[1] + p.z * col[2];
    }

    // an useless duplicate of the * operator, named %, just to prove a point
    Vector3 operator % (Vector3 p) const {
        // matrix vector product as a SEQUENCE OF ROW/VECTOR dot products
        return Vector3( dot(row(0),p) , dot(row(1),p) , dot(row(2),p) );
    }

    // matrix-matrix multiplication
    Mat3 operator * (const Mat3 &p) const{
        return Mat3( (*this) * p.col[0] , (*this) * p.col[1] , (*this) * p.col[2] );
    }

    void invert(){ // in-place inversion
        (*this) = inverse();
    }

    Mat3 inverse() const { // out-of-place inversion
        Mat3 res ( cross( col[1],col[2] ) ,
                   cross( col[2],col[0] ) ,
                   cross( col[0],col[1] ) );
        res /= det();
        res.transpose();
        return res;
    }

    void operator /= (Scalar k){
        col[0] /= k;
        col[1] /= k;
        col[2] /= k;
    }

    void transpose(){
        std::swap( col[0].y , col[1].x ); // x.y , y.z
        std::swap( col[2].x , col[0].z ); // x.z , z.x
        std::swap( col[1].z , col[2].y ); // z.x , x.z
    }

    Mat3 transposed() const {
        return Mat3( row(0),row(1),row(2) );
    }

    Scalar det() const {
        return dot( cross(col[0],col[1]) , col[2] );
    }

};

// vector-matrix product (here, both the b vector and the result are considered ROW vectors)
inline Vector3 operator*( const Vector3& b , const Mat3& A ){
    return A.transposed() * b;
}

inline bool areEqual( const Mat3& a, const Mat3& b ){
    return areEqual(a.col[0],b.col[0])
        && areEqual(a.col[1],b.col[1])
        && areEqual(a.col[2],b.col[2]);
}


}
