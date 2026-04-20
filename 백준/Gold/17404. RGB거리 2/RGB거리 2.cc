#include <iostream>
#include <algorithm>

using namespace std;

// r[i] = min(g[i-1],b[i-1]) + rcost[i]
// r[i] += min(g[i-1],b[i-1])
// 

const int MAX = 1e9;

int d[1001][3] = { 0, };
int cost[1001][3] = { 0, };

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < n + 1; i++)
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	int ans = MAX;

	for (int start = 0; start < 3; start++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == start) d[1][i] = cost[1][i];
			else d[1][i] = MAX;
		}

		for (int i = 2; i < n + 1; i++)
		{
			d[i][0] = cost[i][0] + min(d[i - 1][1], d[i-1][2]);
			d[i][1] = cost[i][1] + min(d[i - 1][0], d[i-1][2]);
			d[i][2] = cost[i][2] + min(d[i - 1][0], d[i-1][1]);
		}

		for (int end = 0; end < 3; end++)
		{
			if (end == start) continue;
			ans = min(ans, d[n][end]);
		}
	}

	cout << ans;
	return 0;
}