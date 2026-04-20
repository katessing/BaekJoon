#include <iostream>
#include <algorithm>
using namespace std;

// d[i] != d[i-1]
// d[i+1] != d[i]

// r[1], g[1], b[1]
// r[2] = g[1] + cost[r], b[1] + cost // 같은 색깔일 때는 cost 무한.
// 

const int MAX = 1e9;

int input[1001][3]; //rgb
int cost[1001][3]; //rgb

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < n+1; i++)
	{
		int r, g, b;
		cin >> r >> g >> b;
		input[i][0] = r;
		input[i][1] = g;
		input[i][2] = b;
	}

	for (int i = 1; i < n+1; i++)
	{
		cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + input[i][0];
		cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + input[i][1];
		cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + input[i][2];
	}

	cout << min({ cost[n][0],cost[n][1],cost[n][2] });

	return 0;
}