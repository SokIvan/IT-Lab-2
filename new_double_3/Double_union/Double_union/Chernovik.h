#pragma once



template<int e, int m>
void PAYNE_HANEK(Floating_Point<e, m>& x, int& znak)
{

	unsigned int M[4] = { 0,0,0,0 }, j = (x.D.ex - m - 1), jk = j;
	//int i2 = 0;
	//Floating_Point<e, m> PI4X = 0,k, X = x / pow(2, int(x.D.ex - m - 1));






	uint64_t XMas[2] = { 0,0 };

	jk = 1023 - jk;
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






	int i = 0;
	for (; i < 128; i++)
	{
		//cout << "ITISBREAK: " << (i + jk) / 32 << endl;
		M[i / 32] += check_bit(DIV_2_ON_PI[(i + jk) / 32], (i + jk) % 32) * pow(2, i % 32);                         ///Новый код
	}


	for (int n_M = 0; n_M < 4; n_M++)
	{
		cout << endl << "M[" << n_M << "] = " << M[n_M];
	}
	cout << endl << endl;

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
	//umn = 2 << 30;
	XMas[1] = x.D.man & 0x00000000ffffffff;
	XMas[0] = (x.D.man >> 32) & 0x00000000ffffffff;


	cout << endl << endl << " XMas[1] = " << XMas[1] << endl << " XMas[0] = " << XMas[0] << endl << endl;
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
	uint64_t k1 = x1 * M[0];                  //---------------------------------{ M[1] ---> M[0] }
	uint64_t k2 = (M[1] * x1 + M[0] * x2);
	uint64_t k3 = (M[2] * x1 + M[1] * x2);
	uint64_t k4 = (M[3] * x1 + M[2] * x2);
	uint64_t k5 = M[3] * x2;

	cout << " x1 = " << x1 << endl;
	cout << " x2 = " << x2 << endl;
	cout << " k1 = " << k1 << endl;
	cout << " k2 = " << k2 << endl;
	cout << " k3 = " << k3 << endl;
	cout << " k4 = " << k4 << endl;
	cout << " k5 = " << k5 << endl;

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

	/*
	unsigned int fc[] = {
		f(k5) ,
		f(k4 + c(k5) ),
		f(k3 + c(k4) ),
		f(k2 + c(k3) ),
		f(k1 + c(k2) ),
		c(k1)
	};
	*/


	cout << "fc[0] = " << fc[0] << endl;
	cout << "fc[1] = " << fc[1] << endl;
	cout << "fc[2] = " << fc[2] << endl;
	cout << "fc[3] = " << fc[3] << endl;
	cout << "fc[4] = " << fc[4] << endl;
	cout << "fc[5] = " << fc[5] << endl;



	int n = (x.D.ex - 1023 + m + 53), nip = 0;
	cout << "Before man: ";
	cout << endl << "  |{-------[ n=" << n << endl;
	while (check_bit(fc[n / 32], 32 - n % 32) != 1)
	{
		//cout << check_bit(fc[n / 32], 32 - n % 32);
		nip++;
		n++;

	}///Новый код





	n++;
	cout << endl << "  |{-------[ n=" << n << endl;
	cout << endl << "--------------------" << endl << "XM = " << xM.D.f << endl << "--------------------" << endl << endl;
	cout << endl << "N+ was : " << nip << endl;
	cout << endl << "Man:";
	for (int i = 0; i < 53; i++)
	{
		xM.D.man += check_bit(fc[(n + i) / 32], (n + i) % 32) * pow(2, i);
		cout << check_bit(fc[(n + i) / 32], (n + i) % 32);
		///Новый код
//		cout << "XM.man bit " << i << " = " <<check_bit(fc[(n + i) / 32], (n + i) % 32) * pow(2, i) << endl; ///показывает одни нули

	}
	cout << endl;
	cout << endl << "--------------------" << endl << "XM = " << xM.D.f << endl << "--------------------" << endl << endl;
	xM.D.ex = 1023 - nip;
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
	cout << endl << "--------------------" << endl << "XM = " << xM.D.f << endl << "--------------------" << endl << endl;
	znak = check_bit(fc[(x.D.ex - 1023 + m - 1) / 32], (x.D.ex - 1023 + m - 1) % 32) + check_bit(fc[(x.D.ex - 1023 + m - 2) / 32], (x.D.ex - 1023 + m - 2) % 32) * 2;                         ///Новый код
	znak = znak % 4;
	cout << "Znak was: " << znak << endl;

	cout << "XM for znak was: " << xM.D.f << endl;
	cout << "1*PI/2 =  " << 1 * M_PI_2 << " znak = 0" << endl;
	cout << "2*PI/2 =  " << 2 * M_PI_2 << " znak = 1" << endl;
	cout << "3*PI/2 =  " << 3 * M_PI_2 << " znak = 2" << endl;
	cout << "4*PI/2 =  " << 4 * M_PI_2 << " znak = 3" << endl;

	cout << endl << "--------------------" << endl << "XM = " << xM.D.f << endl << "--------------------" << endl << endl;







	xM.D.f = (xM.D.f / M_PI_4);




	//	cout << xM.D.f << endl;
	//	cout << x.D.f << endl;

	cout << endl << "--------------------" << endl << "XM = " << xM.D.f << endl << "--------------------" << endl << endl;
	cout << "cos XM  = " << cos(xM.D.f) << endl;
	cout << "sin XM  = " << sin(xM.D.f) << endl;
	cout << sin(xM.D.f) * sin(xM.D.f) + cos(xM.D.f) * cos(xM.D.f) << endl;
	cout << "cos x = " << cos(x.D.f) << endl;
	cout << "sin x = " << sin(x.D.f) << endl;
	cout << "Difference sin: " << sin(xM.D.f) - sin(x.D.f) << endl;
	cout << "Difference cos: " << cos(xM.D.f) - cos(x.D.f) << endl;

	//	cout << "M[0]" << M[0] << endl;
	//	cout << "M[1]" << M[1] << endl;
	//	cout << "M[2]" << M[2] << endl;
	//	cout << "M[3]" << M[3] << endl;















	x = xM;





}

