#include "Black_Sholz.h"





int main()
{
	double x = 13.2351;
	Floating_Point<11, 52> CO(x), SI(x), L(x), xx;

	cout << "X was:";
	for (int i = 0; i < 53; i++)
	{
		cout << check_bit(CO.D.man, i);
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


	int N = 200;
	Floating_Point<11, 52>* mas1 = new Floating_Point<11, 52>[N];
	Floating_Point<11, 52>* mas2 = new Floating_Point<11, 52>[N];
	Floating_Point<11, 52>* mas3 = new Floating_Point<11, 52>[N];
	Floating_Point<11, 52>* mas4 = new Floating_Point<11, 52>[N];
	Get_Optional_Price(mas1, mas2, mas3, mas4, N);

}
