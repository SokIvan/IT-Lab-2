#include "Floating_Point.h"

double LuT[18] =
{
	sin(3 * M_PI / 8.0),
	sin(1 * M_PI / 4.0),
	sin(1 * M_PI / 8.0),
	0.0,
	0.0,
	sin(1 * M_PI / 8.0),
	sin(1 * M_PI / 4.0),
	sin(3 * M_PI / 8.0),
	cos(3 * M_PI / 8.0),
	cos(1 * M_PI / 4.0),
	cos(1 * M_PI / 8.0),
	1.0,
	1.0,
	cos(1 * M_PI / 8.0),
	cos(1 * M_PI / 4.0),
	cos(3 * M_PI / 8.0),
	10.0/M_PI,
	M_PI/2.0


};

double xLuT[8] =
{
	(-3)* M_PI / 8.0,
	(-1)* M_PI / 4.0,
	(-1)* M_PI / 8.0,
	0.0,
	0.0,
	1 * M_PI / 8.0,
	1 * M_PI / 4.0,
	3 * M_PI / 8.0,
};





const unsigned int DIV_2_ON_PI[]
{
	2734261102 >> 1,
	1313084713 >> 1,
	4230436817 >> 1,
	4113882560 >> 1,
	3680671129 >> 1,
	1011060801 >> 1,
	4266746795 >> 1,
	3736847713 >> 1,
	3072618042 >> 1,
	1112396512 >> 1,
	105459434 >> 1,
	164729372 >> 1,
	4263373596 >> 1,
	2972297022 >> 1,
	3900847605 >> 1,
	784024708 >> 1,
	3919343654 >> 1,
	3026157121 >> 1,
	965858873 >> 1,
	2203269620 >> 1,
	2625920907 >> 1,
	3187222587 >> 1,
	536385535 >> 1,
	3724908559 >> 1,
	4012839307 >> 1,
	1510632735 >> 1,
	1832287951 >> 1,
	667617719 >> 1,
	1330003814 >> 1,
	2657085997 >> 1,
	1965537991 >> 1,
	235 >> 1
};




bool check_bit(const unsigned int digit,int number)
{
	return !((digit>>number)%2==0);
}












unsigned int f(uint64_t x)
{
	x = x & 0x00000000ffffffff;
	return x;
}

unsigned int c(uint64_t x)
{
	x = (x & 0xffffffff00000000) >> 32;
	return x;
}




template<int e, int m>
void PAYNE_HANEK(Floating_Point<e, m>& x, int &znak)
{
	
	unsigned int M[4] = { 0,0,0,0 }, p = 50, j = (x.D.ex - m - 1), i = j % 32, jk = j, J = 0, umn = 2 << (i - 1);
	int i2 = 0;
	Floating_Point<e, m> PI4X = 0,k, X = x / pow(2, int(x.D.ex - m - 1));

	uint64_t XMas[2] = { 0,0 };

	jk = 1023-jk;
	// index: DIV_2_ON_PI[jk/32]:DIV_2_ON_PI[jk/32+4] ->M[0]:M[3]
// bit: DIV_2_ON_PI[jk:((jk+31)/32)*32] -> M[0:x]
// bit: DIV_2_ON_PI[((jk+31)/32)*32:((jk+31)/32)*32+32] -> M[0][x:32] и M[1][0:x]
// bit: DIV_2_ON_PI[((jk+31)/32)*32+32:((jk+31)/32)*32+64] -> M[1][x:32] и M[2][0:x]
// bit: DIV_2_ON_PI[((jk+31)/32)*32+64:((jk+31)/32)*32+96] -> M[2][x:32] и M[3][0:x]
// bit: DIV_2_ON_PI[((jk+31)/32)*32+96:jk+128] -> M[3][x:32]

	/*
	int nn = 0;
	for (int s = 0;s<4;s++,nn+=32)
		for (int it = jk; it < ((jk + 31) / 32) * 32+nn; it++)
		{
			M[s] += check_bit(DIV_2_ON_PI[((it + 31) / 32) * 32], it % 32);
		}
		*/
	for (int i = 0; i < 128; i++)
	{
		M[i / 32] += check_bit(DIV_2_ON_PI[(i + jk) / 32],(i+jk)%32) * pow(2,i%32);                         ///Новый код
	}                                                                         /// M[1] и M[2] всегда получаются 0




	/*
	while (jk < (x.D.ex + m + 1 + p))
	{
		for (; i < 32 && jk < (x.D.ex + m + 1 + p); i++,jk++,i2++)
		{
			M[J] += umn*check_bit(DIV_2_ON_PI[jk/32],32-i);
			
			umn >>= 1;
		}
		umn = 2 << 30;
		J++;
		i = 0;
	}
	*/
	umn = 2 << 30;
	XMas[1] = X.D.man & 0x00000000ffffffff;
	XMas[0] = (X.D.man >> 32) & 0x00000000ffffffff;
	/*
	for (i = 0; i < 32; i++)
	{
		XMas[0] += umn * check_bit(X.D.man, 32 - i);
		umn >>= 1;
	}
	umn = 2 << 30;
	for (i = 0; i < 32; i++)
	{
		XMas[1] += umn * check_bit(X.D.man<<32, 32 - i);
		umn >>= 1;
	}
	
	*/



	Floating_Point<e, m> xM;


//	X= x1 * 2^32   + x2

	uint64_t x1 = XMas[0];
	uint64_t x2 = XMas[1];
	uint64_t k1 = x1 * M[1];
	uint64_t k2 = (M[1] * x1 + M[0] * x2);
	uint64_t k3 = (M[2] * x1 + M[1] * x2);
	uint64_t k4 = (M[3] * x1 + M[2] * x2);
	uint64_t k5 = M[3] * x2;

//	cout << "x1= " << x1 << " x2= " << x2 << endl;
//	cout << "k1= " << k1 << endl << "k2= " << k2 << endl << "k3= " << k3 << endl << "k4= " << k4 << endl << "k5= " << k5 << endl;

	//f
	//c
//	cout << "for " << x.D.ex-1023 + m + 1 << " to " << x.D.ex-1023 + m + 53 << endl;
	unsigned int fc[] = { 
		f(k5) ,
		(f(f(k4) + c(k5))),
		(f(f(k3) + c(k4) + c(f(k4) + c(k5)))),
		(f(f(k2) + c(k3) + c(f(k4) + c(f(k3) + c(k4) + c(f(k4) + c(k5)))))),
		(f(f(k1) + c(k2) + c(f(k4) + c(f(k2) + c(k3) + c(f(k4) + c(f(k3) + c(k4) + c(f(k4) + c(k5)))))))),
		(f(c(k1) + c(f(k1) + c(k2) + c(f(k4) + c(f(k2) + c(k3) + c(f(k4) + c(f(k3) + c(k4) + c(f(k4) + c(k5)))))))))
	};
//	cout << "fc[0] = " << fc[0] << endl;
//	cout << "fc[1] = " << fc[1] << endl;
//	cout << "fc[2] = " << fc[2] << endl;
//	cout << "fc[3] = " << fc[3] << endl;
//	cout << "fc[4] = " << fc[4] << endl;
//	cout << "fc[5] = " << fc[5] << endl;

	int n = (x.D.ex - 1023 + m + 53),nip = 0;
	while (check_bit(fc[n / 32], 32 - n % 32) != 1)
	{
		nip++;
		n++;
	}///Новый код
	n++;

	for (int i = 0; i < 53; i++)
	{
		xM.D.man += check_bit(fc[(n + i) / 32],(n + i) % 32) * pow(2, i);                         ///Новый код
//		cout << "XM.man bit " << i << " = " <<check_bit(fc[(n + i) / 32], (n + i) % 32) * pow(2, i) << endl; ///показывает одни нули

	}
	xM.D.ex = 1023-nip;
//	cout << "XM F: = " << xM.D.f << endl;
	/*
	for (int it1 = (x.D.ex - 1023 + m + 1) % 32; it1 < n; it1++)
	{
		if (it1 % 32 == 0 && it1!=0)
		{
			n -= 32;
			it1 -= 32;
		}
		xM.D.man += fc[(x.D.ex - 1023 + m + 1) / 32] && pow(2,32-it1);
	}
	*/
	
	znak = check_bit(fc[(x.D.ex - 1023 + m -1)/32],(x.D.ex - 1023 + m - 1) % 32) + check_bit(fc[(x.D.ex - 1023 + m - 2)/32],(x.D.ex - 1023 + m - 2)%32)*2;                         ///Новый код
	znak = znak % 4;                                                         //znak всегда получается 0
	cout << "Znak was: " << znak << endl;
	


	xM.D.f = xM.D.f * (M_PI / 4.0);
	
//	cout << xM.D.f << endl;
//	cout << x.D.f << endl;

	cout << "X was:" << xM.D.f << endl;
	cout << "sin XM  = " << sin(xM.D.f) << endl;
	cout << "cos XM  = " << cos(xM.D.f) << endl;
	cout << sin(xM.D.f) * sin(xM.D.f) + cos(xM.D.f) * cos(xM.D.f) << endl;
	cout << "cos x = " << cos(x.D.f) << endl;
	cout << "sin x = " << sin(x.D.f) << endl;

//	cout << "M[0]" << M[0] << endl;
//	cout << "M[1]" << M[1] << endl;
//	cout << "M[2]" << M[2] << endl;
//	cout << "M[3]" << M[3] << endl;
	


	x = xM;





}















template<int e,int m>
void redo_sin_cos(Floating_Point<e,m> &for_sin, Floating_Point<e,m> &for_cos, Floating_Point<e,m> x,int znak)
{
	




	Floating_Point<e, m> last_sin, last_cos, next_sin, next_cos;

	last_sin = x;
	last_cos = 1.0;
	for_sin = last_sin;
	for_cos = last_cos;

	for (int i = 1; i < 4; i++)
	{
		next_sin = x * x / (2.0 * i) / (2.0 * i + 1) * (-1.0);
		for_sin = MY_FMA(last_sin, next_sin, for_sin);
		last_sin = last_sin * next_sin;

		next_cos = x * x / (2.0 * i) / (2.0 * i - 1) * (-1.0);
		for_cos = MY_FMA(last_cos, next_cos, for_cos);
		last_cos = last_cos * next_cos;
	}


}







template<int e, int m>
Floating_Point<e, m> MY_SIN(Floating_Point<e, m>& x)
{
	int znak;
	PAYNE_HANEK(x, znak);
	int i = int(x.D.f * LuT[17] + 4);
	Floating_Point<e, m> msin, mcos, Sign(xLuT[i]), y;
	y = x - xLuT[i];
	redo_sin_cos(msin, mcos, y,znak);
	return msin * LuT[i + 8] - mcos * LuT[i] * ~int((Sign.D.sign * (-2)));
}
template<int e, int m>
Floating_Point<e, m> MY_COS(Floating_Point<e, m>& x)
{
	int znak;
	PAYNE_HANEK(x, znak);
	int i = int(x.D.f * LuT[17] + 4);
	Floating_Point<e, m> msin, mcos, Sign(xLuT[i]), y;
	y = x - xLuT[i];
	redo_sin_cos(msin, mcos, y, znak);
	return mcos * LuT[i + 8] + msin * LuT[i] * ~int((Sign.D.sign * (-2)));
}







template<int e, int m>
class ERFi
{


public:
	template<int M = m>
	typename std::enable_if<M <= 5, Floating_Point<e, m>>::type
		Erf(Floating_Point<e, m> x)
	{
		double a1 = 0.278393;
		double a2 = 0.230389;
		double a3 = 0.000972;
		double a4 = 0.078108;

		Floating_Point<e, m> erf = 1 - 1 / pow(1 + 0.278393 * x.D.f + 0.230389 * x.D.f + 0.000972 * x.D.f + 0.078108 * x.D.f, 4);
		return erf;
	}
	template<int M = m>
	typename std::enable_if<(M <= 10 && M > 5), Floating_Point<e, m>>::type
		Erf(Floating_Point<e, m> x)
	{
		double p = 0.47047;
		double a1 = 0.3480242;
		double a2 = -0.0958798;
		double a3 = 0.7478556;

		Floating_Point<e, m> t = 1 / (1 + p * x.D.f);

		x = x.exp_function(10);
		Floating_Point<e, m> ex = x.D.f;
		ex *= ex;
		ex = 1 / ex; // e^(-x^2)

		Floating_Point<e, m> erf = 1 - (1 + a1 * t + a2 * t * t + a3 * t * t * t) * ex;
		return erf;
	}
	template<int M = m>
	typename std::enable_if<(M > 10), Floating_Point<e, m>>::type
		Erf(Floating_Point<e, m> x)
	{
		double p = 0.3275911;
		double a1 = 0.254829592;
		double a2 = -0.284496736;
		double a3 = 1.421413741;
		double a4 = -1.453152027;
		double a5 = 1.061405429;

		Floating_Point<e,m> t = 1 / (1 + p * x.D.f);

		x = x.exp_function(10);
		Floating_Point<e,m> ex = x.D.f;
		ex = ex* ex;
		ex = 1 / ex.D.f; // e^(-x^2)
		double tt = t.D.f;
		Floating_Point<e, m> erf = ex*(1 + a1 * tt + a2 * tt * tt + a3 * tt * tt * tt + a4 * pow(tt, 4) + a5 * pow(tt, 5)) * (-1) + 1;
		return erf;
	}
};

template<int e,int m>
Floating_Point<e, m> Erf_func(Floating_Point<e,m>& x)
{
	ERFi<e, m> xret;
	xret = xret.Erf(x);
	return xret;
}


