#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[20][20];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	// n = 4 -> 1,2 / 1,3 / 1,4 / 2, 3 / 2, 4
	// start가 결정되면, link는 어떻게 고르지??
	// mark를 해두고, 마크 안된 걸 다 집어 넣기??

	// n=6
	// 1,2,3 -> 12, 13, 23, 21,23,32

	

	int min_diff = 1e9;

	for (int i = 0; i < (1 << n); i++)
	{
		if (__builtin_popcount(i) == n / 2)
		{
			int start_sum = 0;
			int link_sum = 0;

			vector<int> start;
			vector<int> link;

			for (int j = 0; j < n; j++)
			{
				if (i & (1 << j))
				{
					start.push_back(j + 1);
				}
				else
				{
					link.push_back(j + 1);
				}
			}

			for (int x = 0; x < start.size(); x++)
			{
				for (int y = 0; y < start.size(); y++)
				{
					if (x == y) continue;
					start_sum += arr[start[x] - 1][start[y] - 1];
					link_sum += arr[link[x] - 1][link[y] - 1];
				}
			}

			int diff = abs(start_sum - link_sum);
			if (min_diff > diff) min_diff = diff;
		}
	}

	cout << min_diff;
}