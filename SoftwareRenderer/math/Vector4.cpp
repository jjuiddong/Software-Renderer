
#include "stdafx.h"
#include "Math.h"


Vector4::Vector4(const Vector3 &v) : x(v.x), y(v.y), z(v.z), w(1) 
{
}

Vector4 Vector4::operator * ( const Matrix44& m )
{
	float	fRHW = 1.0F / ( x * m._14 + y * m._24 + z * m._34 + m._44 );	

	Vector4	v;
	v.x = ( x * m._11 + y * m._21 + z * m._31 + m._41 ) * fRHW;
	v.y = ( x * m._12 + y * m._22 + z * m._32 + m._42 ) * fRHW;
	v.z = ( x * m._13 + y * m._23 + z * m._33 + m._43 ) * fRHW;
	v.w = ( x * m._14 + y * m._24 + z * m._34 + m._44 ) * fRHW;
	return v;	
}
