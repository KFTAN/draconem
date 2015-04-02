// TimeSpanDriver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "TimeSpan.h";

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	TimeSpan t(1, 2.5, 3);
	TimeSpan t1(1.234535, 2.43, 0);
	TimeSpan t2(1, 34, 120);
	TimeSpan t3(1, -30, -120);
	TimeSpan t4(5, 68, 300);
	TimeSpan t5(933, -9820.839271349, 83);
	TimeSpan t6(12000);
	cout << "t6 before: " << t6;
	t6.setHours(60);
	t6.setMinutes(8000);
	t6.setSeconds(300);
	cout << "t: " << t;
	cout << "t1: " << t1;
	cout << "t2: " << t2;
	cout << "t3: " << t3;
	cout << "t4: " << t4;
	cout << "t5: " << t5;
	cout << "t6 after: " << t6;
	TimeSpan dur1(77.4, 15, 6), dur2(127.86), dur3(8, -23, 0), dur4(0, 0, 0);
	TimeSpan dur5(-3, 73, 2), dur6(7, 35, 120), dur7, dur8;
	dur7 = dur1 + dur3;
	cout << "dur1: " << dur1;
	cout << "dur2: " << dur2;
	cout << "dur3: " << dur3;
	cout << "dur4: " << dur4;
	cout << "dur5: " << dur5;
	cout << "dur6: " << dur6;
	cout << "dur7: " << dur7;
	dur7 += dur3;
	cout << "dur3: " << dur3;
	cout << "dur7: " << dur7;
	/*if (dur3 != dur6)
	{
		cout << "Durations are different." << endl;
	}
	else
	{
		cout << "Durations are the same" << endl;
	}
	cout << "dur7: before unary " << dur7;
	dur7 = -dur7;
	cout << "dur7: after unary " << dur7;
	cout << (-dur7 != dur7) << endl;
	cout << "true: " << true << " false: " << false << endl;
	TimeSpan tester1(1, 2, 3);
	TimeSpan tester2(1, 2, 3);
	cout << (tester1 == tester2) << endl;
	cout << (tester1 != tester2) << endl;
	*/

	cin.get();

	return 0;
}

