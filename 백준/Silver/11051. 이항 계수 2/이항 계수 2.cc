#include <iostream>

using namespace std;

// N_C_K = N-1_C_K-1 + N-1_C_K
// D[i][j] = D[i-1][j-1] + D[i-1][j]

int d[1001][1001] = { 0, };

int main()
{
	int n, k;
	
	cin >> n >> k;

	d[1][1] = 1; // 1C1
	
	for (int i = 0; i < n + 1; i++)
	{
		d[i][0] = 1;
	}

	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 1; j < k + 1; j++)
		{
			if (j == 1)
			{
				d[i][j] = i % 10007;
				//cout << "j1," << d[i][j] << ", " << i << ", " << j << endl;
			}
			else
			{
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % 10007;
				//cout << "else," << d[i][j] << ", " << i << ", " << j << endl;
			}
		}
	}

	cout << d[n][k];

	return 0;
}