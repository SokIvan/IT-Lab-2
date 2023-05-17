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
	1367130551 ,//ok 1
	656542356  ,//ok 2
	4262702056 ,//ok 3
	4204424928 ,//ok 4
	1840335564 ,//ok 5
	2653014048 ,//ok 6 
	4280857045 ,//ok 7
	4015907504 ,//ok 8
	3683792669 ,//ok 9
	556198256  ,//ok 10
	52729717   ,//ok 11
	82364686   ,//ok 12
	2131686798 ,//ok 13
	1486148511 ,//ok 14
	1950423802 ,//ok 15
	2539496002 ,//ok 16
	1959671827 ,//ok 17
	1513078560 ,//ok 18
	2630413084 ,//ok 19
	3249118458 ,//ok 20
	1312960453 ,//ok 21
	3741094941 ,//ok 22
	2415676415 ,//ok 23
	4009937927 ,//ok 24
	4153903301 ,//ok 25
	2902800015 ,//ok 26
	3063627623 ,//ok 27
	2481292507 ,//ok 28
	2812485555 ,//ok 29
	1328542998 ,//ok 30
	3130252643 ,//ok 31
	245 ,       //ok 32
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
	//x = (x - f(x)) >> 32;
	x = (x >> 32) & 0x00000000ffffffff;
	return x;
}




template<int e, int m>
void PAYNE_HANEK(Floating_Point<e, m>& x, int &znak)
{


	cout << endl << endl << endl << "------------| x.D.ex = " << x.D.ex << endl << endl << endl;

//|===------------===|  [ Корень зла ]  |===---------------------------------===|
																			  //|
	unsigned int M[4] = { 0,0,0,0 }, j = ((-1) * x.D.ex + 1023 + m - 1), jk = j;//50;//j;  //|           
																			  //|
//|===-----------------------------------------------------------------------===|

	// e=11   m=52
	//D.ex=1026


	cout << endl << endl << "x.man=" << x.D.man << endl << endl;
	cout << endl << "x=" <<x.D.f<<endl<<endl<< "jk=" << jk << endl;


	uint64_t XMas[2] = { 0,0 };

	//jk = 1023-jk;                                                       *****Changed*****

	cout << endl << "jk=" << jk << endl;

		


	for (int i = 0; i < 2*m+22; i++)
	{

		M[i / 32] += check_bit(DIV_2_ON_PI[(jk + i) / 32], (jk + i) % 32) * pow(2, i % 32);
                   
	}         
	//---------------------------------------------------------------------------------------------------

	for (int n_M = 0; n_M < 4; n_M++)
	{
		cout << endl << "M[" << n_M << "] = " << M[n_M];
	}
	cout << endl<<endl<< x.D.man;


	XMas[1] = x.D.man & 0x00000000ffffffff;
	XMas[0] = (x.D.man >> 32) & 0x00000000ffffffff;


	cout << endl << endl << " XMas[1] = " << XMas[1] << endl << " XMas[0] = " << XMas[0] << endl << endl;




	Floating_Point<e, m> xM;




	uint64_t x1 = XMas[0];
	uint64_t x2 = XMas[1];
	uint64_t k1 = x2 * M[3]+x1*M[2];                  
	uint64_t k2 = (M[2] * x2 + M[1] * x1);
	uint64_t k3 = (M[1] * x2 + M[0] * x1);
	uint64_t k4 = M[0] * x2 ;
	//uint64_t k5 = M[3] * x2;

	cout << " x1 = "<< x1 <<endl;
	cout << " x2 = "<< x2 <<endl;
	cout << " k1 = "<< k1 <<endl;
	cout << " k2 = "<< k2 <<endl;
	cout << " k3 = "<< k3 <<endl;
	cout << " k4 = "<< k4 <<endl;
	//cout << " k5 = "<< k5 <<endl;


		
	/*unsigned int*/ uint64_t fc[] = {
		f(k4) ,
		(f(f(k3)+c(k4))),
		(f(f(k2)+c(k3)+c(f(k3) + c(k4)))),
		(f(f(k1)+c(k2)+c(f(k2) + c(k3) + c(f(k3) + c(k4))))),
		(f(c(k1)+ c(f(k1) + c(k2) + c(f(k2) + c(k3) + c(f(k3) + c(k4)))))),
	(f(c(c(k1) + c(f(k1) + c(k2) + c(f(k2) + c(k3) + c(f(k3) + c(k4)))))))
	};
		



	cout << "fc[0] = " << fc[0] << endl;
	cout << "fc[1] = " << fc[1] << endl;
	cout << "fc[2] = " << fc[2] << endl;
	cout << "fc[3] = " << fc[3] << endl;
	cout << "fc[4] = " << fc[4] << endl;
	cout << "fc[5] = " << fc[5] << endl;


	
	int n = (x.D.ex - 1023 + m + 53),nip = 0;
	cout << "Before man: ";
	cout <<endl<< "  |{-------[ n=" << n << endl;
	while (check_bit(fc[n / 32], 32 - n % 32) != 1)
	{
		nip++;
		n++;

	}




	n++;
	cout << endl << "  |{-------[ n=" << n << endl;
	cout << endl <<"--------------------" << endl << "XM = " << xM.D.f << endl <<"--------------------"  << endl << endl;
	cout << endl << "N+ was : " << nip << endl;
	cout << endl << "Man:";
	xM.D.ex = 1023 - nip;
	
	for (int i = 0; i < 52; i++)
	{





		xM.D.man += check_bit(fc[(n + i) / 32],(n + i) % 32) * pow(2, i);        
		cout << check_bit(fc[(n + i) / 32], (n + i) % 32);

	}
	



	cout << endl;
	cout << endl << "--------------------" << endl << "XM = " << xM.D.f << endl << "--------------------"  << endl << endl;
	




	cout << endl << "--------------------" << endl << "XM = " << xM.D.f << endl << "--------------------"  << endl << endl;
	znak =check_bit(fc[(x.D.ex - 1023 + m-1)/32],(x.D.ex - 1023 + m-1 ) % 32) + check_bit(fc[(x.D.ex - 1023 + m - 2)/32],(x.D.ex - 1023 + m - 2)%32);    //*2                     ///Новый код
	znak = znak % 4;                                                         
	cout << "Znak was: " << znak << endl;
	
	cout << "XM for znak was: " << xM.D.f << endl;
	cout << "1*PI/2 =  " << 1*M_PI_2 << " znak = 0" << endl;
	cout << "2*PI/2 =  " << 2*M_PI_2 << " znak = 1" << endl;
	cout << "3*PI/2 =  " << 3*M_PI_2 << " znak = 2" << endl;
	cout << "4*PI/2 =  " << 4*M_PI_2 << " znak = 3" << endl;

	cout << endl << "--------------------" << endl << "XM = " << xM.D.f << endl << "--------------------"  << endl << endl;




	double pp = x.D.f / M_PI_2;
	int p = ceil(pp) - 1;
	p %= 4;


		xM.D.f = (xM.D.f / M_PI_2);
	
		double war = 2.052832;
	
		cout << endl << "--------------------" << endl << "XM = " << xM.D.f << endl << "--------------------"  << endl << endl;
	cout << "cos XM  = " << cos(xM.D.f) << endl;
	cout << "sin XM  = " << sin(xM.D.f) << endl;
	cout << "cos XM(war)  = " << cos(xM.D.f+p*M_PI_2) << endl;
	cout << "sin XM(war)  = " << sin(xM.D.f + p * M_PI_2) << endl;
	cout << "cos x = " << cos(x.D.f) << endl;
	cout << "sin x = " << sin(x.D.f) << endl;
	cout << "Difference sin: " << sin(xM.D.f) - sin(x.D.f) << endl;
	cout << "Difference cos: " << cos(xM.D.f) - cos(x.D.f) << endl;














	x =  xM;





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





//-------------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------------





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

		x = exp_function(x,10);
		Floating_Point<e, m> ex = x.D.f,d =  1.0;
		ex = ex* ex;
		ex = d / ex; // e^(-x^2)

		Floating_Point<e, m> erf = (t*a1 + t * t*a2 + t * t * t*a3+1) * ex*(-1)+1;
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

		x = exp_function(x,10);
		Floating_Point<e,m> ex = x.D.f;
		ex = ex* ex;
		ex = 1 / ex.D.f; // e^(-x^2)
		double tt = t.D.f;
		Floating_Point<e, m> erf = ex*(1 + a1 * tt + a2 * tt * tt + a3 * tt * tt * tt + a4 * pow(tt, 4) + a5 * pow(tt, 5)) * (-1) + 1;
		return erf;
	}
};

template<int e,int m>
Floating_Point<e, m> Erf_func(Floating_Point<e,m> x)
{
	ERFi<e, m> xret;
	return xret.Erf(x);
}


