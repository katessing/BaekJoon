#include <iostream>

using namespace std;

int stair[301];
int d[301];

int N;

// 1. d[i-2]
// 2. d[i-3] + arr[i-1]

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> stair[i];
	}

	for (int i = 0; i < N; i++)
	{
		if (i == 0) d[0] = stair[0];
		else if (i == 1) d[1] = d[0] + stair[1];
		else if (i == 2) d[2] = max(d[0],stair[1]) + stair[2];
		else d[i] = max(d[i - 2], d[i - 3] + stair[i - 1]) + stair[i];
	}

	cout << d[N - 1];
}