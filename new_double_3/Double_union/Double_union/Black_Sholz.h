#include "SinCosFunc.h"
#pragma simd



template<int e,int m>
void Get_Optional_Price(Floating_Point<e, m>*m1, Floating_Point<e, m>*m2, Floating_Point<e, m>*m3, Floating_Point<e, m>*m4, int size)
{
	Floating_Point<e, m> r = 0.045,sig = 0.333,d1, d2,sig2_05 = sig*sig*0.5,invf,e1,e2;

	for (int i = 0; i < size;i++)
	{
		invf = INVSQRT(sig2_05 * m1[i] * 2);
		d1 = (Log2(m3[i] / m2[i]) + (r + sig2_05) * m1[i]) * invf;
		d1 = (Log2(m3[i] / m2[i]) + (r - sig2_05) * m1[i]) * invf;
		
		e1 = Erf_func(d1 / sqrt(2.0)) * 0.5 + 0.5;
		e2 = Erf_func(d2 / sqrt(2.0)) * 0.5 + 0.5;

		m4[i] = m3[i] * e1 - m2[i] * exp_function(m1[i] * (-1.0) * r,100) * e2;
	}
}