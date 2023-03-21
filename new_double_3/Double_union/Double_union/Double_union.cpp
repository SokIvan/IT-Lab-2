#include "SinCosFunc.h"





int main()
{
	double x = 12.4124;
	Floating_Point<11, 52> CO(x), SI(x), L(x);

	int x1 = 2;

	cout << "check is " << check_bit(x1, 1) << endl;

	cout << L.D.f << endl;
	L = LogE(L);
	cout << "logE: " << L.D.f << endl << endl;
	CO = MY_COS(CO);
	SI = MY_COS(SI);
	cout << "Mycos: " << CO.D.f << "   Realcos: " << cos(x) << endl;
	cout << "Mycsin: " << SI.D.f << "   Realsin: " << sin(x) << endl;





}
