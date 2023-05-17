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



	//double x = 41.5253338823;
	//double x = 35.2421485751;
	//double x = 22.6757779608;
	//double x = 50.9501853072;
	double x = 13.251;
	//double x = 57.2332971503;
	//double x = 19.5341853072;
	//double x = 25.8173706144;
	//double x = 32.1;
	//double x = 44.6669265359;
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
	Get_Optional_Price_STD(mas1, mas2, mas3, mas4, N);











	//FP_16



	cout << "\n\nFP_16\n\n";

	int Nf16 = 100;
	double collisionf16 = 0, realf16 = 0, middlecollisionf16 = 0, ourmiddlecollisionf16 = 0;
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

	for (int i = 0; i < Nf16; i++)
	{
		if (fabs(mas4f16[i].D.f - mas4[i].D.f) > collisionf16)
			collisionf16 = fabs(mas4f16[i].D.f - mas4[i].D.f);
	}
	for (int i = 0; i < Nf16; i++)
	{
		ourmiddlecollisionf16 += fabs(mas4f16[i].D.f - mas4[i].D.f);
	}
	ourmiddlecollisionf16 /= double(Nf16);
	Get_Optional_Price_STD(mas1f16, mas2f16, mas3f16, mas4f16, Nf16);

	for (int i = 0; i < Nf16; i++)
	{
		if ( fabs(mas4f16[i].D.f-mas4[i].D.f)>realf16)
		realf16 = fabs(mas4f16[i].D.f - mas4[i].D.f);
	}
	for (int i = 0; i < Nf16; i++)
	{
		middlecollisionf16 += fabs(mas4f16[i].D.f - mas4[i].D.f);
	}
	middlecollisionf16 /= double(Nf16);
	cout << "MAX COLLISION(our functions): " << collisionf16 << endl;
	cout << "MAX COLLISION(std functions): " << realf16 << endl;
	cout << "MIDDLE COLLISION(our functions): " << ourmiddlecollisionf16 << endl;
	cout << "MIDDLE COLLISION(std functions): " << middlecollisionf16 << endl;













	//FP_32
	cout << "\n\nFP_32\n\n";

	int Nf32 = 100;
	double collisionf32 = 0, realf32 = 0, middlecollisionf32 = 0, ourmiddlecollisionf32 = 0;
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

	for (int i = 0; i < Nf32; i++)
	{
		if (fabs(mas4f32[i].D.f - mas4[i].D.f) > collisionf32)
			collisionf32 = fabs(mas4f32[i].D.f - mas4[i].D.f);
	}
	for (int i = 0; i < Nf16; i++)
	{
		ourmiddlecollisionf32 += fabs(mas4f32[i].D.f - mas4[i].D.f);
	}
	ourmiddlecollisionf32 /= double(Nf16);
	Get_Optional_Price_STD(mas1f32, mas2f32, mas3f32, mas4f32, Nf32);

	for (int i = 0; i < Nf32; i++)
	{
		if (fabs(mas4f32[i].D.f - mas4[i].D.f) > realf32)
			realf32 = fabs(mas4f32[i].D.f - mas4[i].D.f);
	}
	for (int i = 0; i < Nf32; i++)
	{
		middlecollisionf32 += fabs(mas4f32[i].D.f - mas4[i].D.f);
	}
	middlecollisionf32 /= double(Nf32);
	cout << "MAX COLLISION(our functions): " << collisionf32 << endl;
	cout << "MAX COLLISION(std functions): " << realf32 << endl;
	cout << "MIDDLE COLLISION(our functions): " << ourmiddlecollisionf32 << endl;
	cout << "MIDDLE COLLISION(std functions): " << middlecollisionf32 << endl;


























	cout << "\n\nFB_16\n\n";

	//FB_16

	int Nb16 = 100;
	double collisionb16 = 0, realb16 = 0, middlecollisionb16 = 0, ourmiddlecollisionb16 = 0;
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

	for (int i = 0; i < Nb16; i++)
	{
		if (fabs(mas4b16[i].D.f - mas4[i].D.f) > collisionb16)
			collisionb16 = fabs(mas4b16[i].D.f - mas4[i].D.f);
	}
	for (int i = 0; i < Nf16; i++)
	{
		ourmiddlecollisionb16 += fabs(mas4b16[i].D.f - mas4[i].D.f);
	}
	ourmiddlecollisionb16 /= double(Nf16);
	Get_Optional_Price_STD(mas1b16, mas2b16, mas3b16, mas4b16, Nb16);

	for (int i = 0; i < Nb16; i++)
	{
		if (fabs(mas4b16[i].D.f - mas4[i].D.f) > realb16)
			realb16 = fabs(mas4b16[i].D.f - mas4[i].D.f);
	}
	for (int i = 0; i < Nf16; i++)
	{
		middlecollisionb16 += fabs(mas4b16[i].D.f - mas4[i].D.f);
	}
	middlecollisionb16 /= double(Nf16);
	cout << "MAX COLLISION(our functions): " << collisionb16 << endl;
	cout << "MAX COLLISION(std functions): " << realb16 << endl;
	cout << "MIDDLE COLLISION(our functions): " << ourmiddlecollisionb16 << endl;
	cout << "MIDDLE COLLISION(std functions): " << middlecollisionb16 << endl;

	
}
