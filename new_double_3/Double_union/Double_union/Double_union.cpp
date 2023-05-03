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






	cout << "\n\n\n\n\n BLACK SHOLS\n\n" << endl;
	cout << "\n\nStandart double\n\n";

	//          usual double
	int N = 100;
	Floating_Point<11, 52> collision = 0,real;
	Floating_Point<11, 52>* mas1 = new Floating_Point<11, 52>[N];
	Floating_Point<11, 52>* mas2 = new Floating_Point<11, 52>[N];
	Floating_Point<11, 52>* mas3 = new Floating_Point<11, 52>[N];
	Floating_Point<11, 52>* mas4 = new Floating_Point<11, 52>[N];
	mas1[0] = 13.2;
	mas2[0] = 2.7;
	mas3[0] = 11.0;
	for (int i = 1; i < N; i++)
	{
		mas1[i] = mas1[0] + mas1[i - 1];
		mas2[i] = mas2[0] + mas2[i - 1];
		mas3[i] = mas3[0] + mas3[i - 1];
	}
	Get_Optional_Price(mas1, mas2, mas3, mas4, N);
	for (int i = 0; i < N; i++)
	{
		collision = collision + mas4[i];
	}
	Get_Optional_Price_STD(mas1, mas2, mas3, mas4, N);
	for (int i = 0; i < N; i++)
	{
		real = real + mas4[i];
	}
	cout << "Summ our: " << collision.D.f << "   Summ std: " << real.D.f << endl;
	cout << "MIDDLE Collision on " << N << " elem is:" << (1.0 - collision.D.f / real.D.f) << endl << endl << endl;

	//FP_16

	cout << "\n\nFP_16\n\n";

	int Nf16 = 100;
	Floating_Point<5, 10> collisionf16 = 0, realf16 = 0;
	Floating_Point<5, 10>* mas1f16 = new Floating_Point<5, 10>[Nf16];
	Floating_Point<5, 10>* mas2f16 = new Floating_Point<5, 10>[Nf16];
	Floating_Point<5, 10>* mas3f16 = new Floating_Point<5, 10>[Nf16];
	Floating_Point<5, 10>* mas4f16 = new Floating_Point<5, 10>[Nf16];
	mas1f16[0] = 13.2;
	mas2f16[0] = 2.7;
	mas3f16[0] = 11.0;
	for (int i = 1; i < Nf16; i++)
	{
		mas1f16[i] = mas1f16[0] + mas1f16[i - 1];
		mas2f16[i] = mas2f16[0] + mas2f16[i - 1];
		mas3f16[i] = mas3f16[0] + mas3f16[i - 1];
	}
	Get_Optional_Price(mas1f16, mas2f16, mas3f16, mas4f16, Nf16);
	cout << "Black_Sholz(our) is: " << mas4f16[0].D.f << endl;
	for (int i = 0; i < Nf16; i++)
	{
		collisionf16 = collisionf16 + mas4f16[i];
	}
	Get_Optional_Price_STD(mas1f16, mas2f16, mas3f16, mas4f16, Nf16);
	cout << "Black_Sholz(std) is: " << mas4f16[0].D.f << endl;
	for (int i = 0; i < Nf16; i++)
	{
		realf16 = realf16 + mas4f16[i];
	}
	cout << "Summ our: " << collisionf16.D.f << "   Summ std: " << realf16.D.f << endl;
	cout << "MIDDLE Collision on " << Nf16 << " elem is:" << (1.0 - collisionf16.D.f / realf16.D.f) << endl << endl << endl;

	//FP_32
	cout << "\n\nFP_32\n\n";

	int Nf32 = 100;
	Floating_Point<8, 23> collisionf32 = 0, realf32 = 0;
	Floating_Point<8, 23>* mas1f32 = new Floating_Point<8, 23>[Nf32];
	Floating_Point<8, 23>* mas2f32 = new Floating_Point<8, 23>[Nf32];
	Floating_Point<8, 23>* mas3f32 = new Floating_Point<8, 23>[Nf32];
	Floating_Point<8, 23>* mas4f32 = new Floating_Point<8, 23>[Nf32];
	mas1f32[0] = 13.2;
	mas2f32[0] = 2.7;
	mas3f32[0] = 11.0;
	for (int i = 1; i < Nf32; i++)
	{
		mas1f32[i] = mas1f32[0] + mas1f32[i - 1];
		mas2f32[i] = mas2f32[0] + mas2f32[i - 1];
		mas3f32[i] = mas3f32[0] + mas3f32[i - 1];
	}
	Get_Optional_Price(mas1f32, mas2f32, mas3f32, mas4f32, Nf32);
	cout << "Black_Sholz(our) is: " << mas4f32[0].D.f << endl;
	for (int i = 0; i < Nf32; i++)
	{
		collisionf32 = collisionf32 + mas4f32[i];
	}
	Get_Optional_Price_STD(mas1f32, mas2f32, mas3f32, mas4f32, Nf32);
	cout << "Black_Sholz(std) is: " << mas4f32[0].D.f << endl;
	for (int i = 0; i < Nf32; i++)
	{
		realf32 = realf32 + mas4f32[i];
	}
	cout << "Summ our: " << collisionf32.D.f << "   Summ std: " << realf32.D.f << endl;
	cout << "MIDDLE Collision on " << Nf32 << " elem is:" << (1.0 - collisionf32.D.f / realf32.D.f) << endl << endl << endl;









	cout << "\n\nFB_16\n\n";

	//FB_16

	int Nb16 = 100;
	Floating_Point<8, 7> collisionb16 = 0, realb16 = 0;
	Floating_Point<8, 7>* mas1b16 = new Floating_Point<8, 7>[Nb16];
	Floating_Point<8, 7>* mas2b16 = new Floating_Point<8, 7>[Nb16];
	Floating_Point<8, 7>* mas3b16 = new Floating_Point<8, 7>[Nb16];
	Floating_Point<8, 7>* mas4b16 = new Floating_Point<8, 7>[Nb16];
	mas1b16[0] = 13.2;
	mas2b16[0] = 2.7;
	mas3b16[0] = 11.0;
	for (int i = 1; i < Nf16; i++)
	{
		mas1b16[i] = mas1b16[0] + mas1b16[i - 1];
		mas2b16[i] = mas2b16[0] + mas2b16[i - 1];
		mas3b16[i] = mas3b16[0] + mas3b16[i - 1];
	}
	Get_Optional_Price(mas1b16, mas2b16, mas3b16, mas4b16, Nb16);
	cout << "Black_Sholz(our) is: " << mas4b16[0].D.f << endl;
	for (int i = 0; i < Nb16; i++)
	{
		collisionb16 = collisionb16 + mas4b16[i];
	}
	Get_Optional_Price_STD(mas1b16, mas2b16, mas3b16, mas4b16, Nb16);
	cout << "Black_Sholz(std) is: " << mas4b16[0].D.f << endl;
	for (int i = 0; i < Nb16; i++)
	{
		realb16 = realb16 + mas4b16[i];
	}
	cout << "Summ our: " << collisionb16.D.f << "   Summ std: " << realb16.D.f << endl;
	cout << "MIDDLE Collision on " << Nb16 << " elem is:" << (1.0 - collisionb16.D.f / realb16.D.f) << endl << endl << endl;

	//FB_32

	cout << "\n\nFB_32\n\n";

	int Nb32 = 100;
	Floating_Point<8, 23> collisionb32 = 0, realb32 = 0;
	Floating_Point<8, 23>* mas1b32 = new Floating_Point<8, 23>[Nb32];
	Floating_Point<8, 23>* mas2b32 = new Floating_Point<8, 23>[Nb32];
	Floating_Point<8, 23>* mas3b32 = new Floating_Point<8, 23>[Nb32];
	Floating_Point<8, 23>* mas4b32 = new Floating_Point<8, 23>[Nb32];
	mas1b32[0] = 13.2;
	mas2b32[0] = 2.7;
	mas3b32[0] = 11.0;
	for (int i = 1; i < Nb32; i++)
	{
		mas1b32[i] = mas1b32[0] + mas1b32[i - 1];
		mas2b32[i] = mas2b32[0] + mas2b32[i - 1];
		mas3b32[i] = mas3b32[0] + mas3b32[i - 1];
	}
	Get_Optional_Price(mas1b32, mas2b32, mas3b32, mas4b32, Nb32);
	cout << "Black_Sholz(our) is: " << mas4b32[0].D.f << endl;
	for (int i = 0; i < Nb32; i++)
	{
		collisionb32 = collisionb32 + mas4b32[i];
	}
	Get_Optional_Price_STD(mas1b32, mas2b32, mas3b32, mas4b32, Nb32);
	cout << "Black_Sholz(std) is: " << mas4b32[0].D.f << endl;
	for (int i = 0; i < Nb32; i++)
	{
		realb32 = realb32 + mas4b32[i];
	}
	cout << "Summ our: " << collisionb32.D.f << "   Summ std: " << realb32.D.f << endl;
	cout << "MIDDLE Collision on " << Nb32 << " elem is:" << (1.0 - collisionb32.D.f / realb32.D.f) << endl << endl << endl;
}
