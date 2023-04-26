#include "Black_Sholz.h"





int main()
{
	Floating_Point<11, 52> DD;
	DD.D.sign = 0;
	DD.D.ex = 1023 - 2;
	DD.D.man = 957915674990;

	cout << "DD = " << DD.D.f * M_PI_2 << endl;
	uint64_t M1=592567970761506158, M2 = 430856211390393338, M3=810607516586031372, M4=1219093667032881960,tmp;

	tmp = f(M4);
	cout << endl << endl << endl;
	cout << endl << tmp << endl;

	tmp = f(f(M3) + c(M4));
	cout << endl << tmp << endl;

	tmp = f(f(M2) + c(M3) + c(f(M3) + c(M4)));
	cout << endl << tmp << endl;

	tmp = f(f(M1) + c(M2) + c(f(M2) + c(M3) + c(f(M3) + c(M4))));
	cout << endl << tmp << endl;

	tmp = f(c(M1) + c(f(M1) + c(M2) + c(f(M2) + c(M3) + c(f(M3) + c(M4)))));
	cout << endl << tmp << endl;

	tmp = f(c(c(M1) + c(f(M1) + c(M2) + c(f(M2) + c(M3) + c(f(M3) + c(M4))))));
	cout << endl << tmp << endl;

	cout << endl << endl << endl;

	double x = 13.251;
	Floating_Point<11, 52> CO(x), SI(x), L(x), xx;

	cout << "X was:" << CO.D.ex << endl;
	for (int i = 0; i < 53; i++)
	{
		cout << check_bit(CO.D.man,i);
	}
	cout << endl;

	int x1 = 2;

//	cout << "check is " << check_bit(x1, 1) << endl;

	cout << L.D.f << endl;
	L = LogE(L);
//	cout << "logE: " << L.D.f << endl << endl;
	CO = MY_COS(CO);
	SI = MY_SIN(SI);
	cout << "Mycos: " << CO.D.f << "   Realcos: " << cos(x) << endl;
	cout << "Mysin: " << SI.D.f << "   Realsin: " << sin(x) << endl;


	int N = 1;
	Floating_Point<11, 10>* mas1 = new Floating_Point<11, 10>[N];
	Floating_Point<11, 10>* mas2 = new Floating_Point<11, 10>[N];
	Floating_Point<11, 10>* mas3 = new Floating_Point<11, 10>[N];
	Floating_Point<11, 10>* mas4 = new Floating_Point<11, 10>[N];
	mas1[0] = 5.0;
	mas2[0] = 150.0;
	mas3[0] = 1500.0;

	Get_Optional_Price(mas1, mas2, mas3, mas4, N);
	cout << "Black_Sholz is: " << mas4[0].D.f << endl;
}
