#include <iostream>

using namespace std;

long long P[101];

void MakeP()
{
	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2; // 1 + 3
	P[5] = 2; // 4
	P[6] = 3; // 1 + 5
	P[7] = 4; // 2 + 6
	P[8] = 5; // 3 + 7
	P[9] = 7; // 4 + 8
	P[10] = 9; // 5 + 9
	P[11] = 12; // 6 + 10
	P[12] = 16; // 7 + 11 = 4 + 12 
	for (int i = 13; i <= 100; i++)
	{
		P[i] = P[i - 5] + P[i - 1];
	}
}

int main()
{
	int t;
	cin >> t;

	MakeP();

	/*for (int i = 1; i <= 100; i++)
	{
		cout << P[i] << endl;
	}*/

	for (int i = 0; i < t; i++)
	{
		int input;
		cin >> input;
		cout << P[input] << '\n';
	}
}