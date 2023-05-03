#include "SinCosFunc.h"
#pragma simd


#pragma omp parallel for simd
template<int e, int m>                   // PT                        PK                       PS0                        PC
void Get_Optional_Price(Floating_Point<e, m>* m1, Floating_Point<e, m>* m2, Floating_Point<e, m>* m3, Floating_Point<e, m>* m4, int size)
{
	Floating_Point<e, m> r = 0.11, sig = 0.3, d1, d2, sig2_05 = sig * sig * 0.5, invf, e1, e2;

	for (int i = 0; i < size; i++)
	{
		invf = INVSQRT(sig2_05 * m1[i] * 2);
		d1 = ((r + sig2_05) * m1[i] + Log2(m3[i] / m2[i])) * invf;
		d2 = ((r - sig2_05) * m1[i] + Log2(m3[i] / m2[i])) * invf;

		e1 = Erf_func(d1 / sqrt(2.0)) * 0.5 + 0.5;
		e2 = Erf_func(d2 / sqrt(2.0)) * 0.5 + 0.5;

		m4[i] = m3[i] * e1 - m2[i] * exp_function(m1[i] * (-1.0) * r, 10) * e2;
		m4[i] = m4[i] * (m4[i].D.f > 0);
		//cout << "M4[" << i << "](our) is: " << m4[i].D.f << endl;
	}
}

#pragma omp parallel for simd
template<int e, int m>                   // PT                        PK                       PS0                        PC
void Get_Optional_Price_STD(Floating_Point<e, m>* m1, Floating_Point<e, m>* m2, Floating_Point<e, m>* m3, Floating_Point<e, m>* m4, int size)
{
	Floating_Point<e, m> r = 0.11, sig = 0.3, d1, d2, sig2_05 = sig * sig * 0.5, invf, e1, e2;

	for (int i = 0; i < size; i++)
	{
		invf = INVSQRT(sig2_05 * m1[i] * 2);
		d1 = ((r + sig2_05) * m1[i] + log2(m3[i].D.f / m2[i].D.f)) * invf;
		d2 = ((r - sig2_05) * m1[i] + log2(m3[i].D.f / m2[i].D.f)) * invf;

		e1 = erf(d1.D.f / sqrt(2.0)) * 0.5 + 0.5;
		e2 = erf(d2.D.f / sqrt(2.0)) * 0.5 + 0.5;

		m4[i] = m3[i] * e1 - m2[i] * e2 * exp(r.D.f * m1[i].D.f * (-1.0));
		m4[i] = m4[i] * (m4[i].D.f > 0);

		//cout << "M4["<< i << "](std) is: " << m4[i].D.f << endl;
	}
}