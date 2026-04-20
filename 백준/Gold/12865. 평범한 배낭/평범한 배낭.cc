#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[100'001];

int main()
{
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> arr;
	arr.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		arr.push_back({ w, v });
	}

	for (int i = 0; i < n; i++)
	{
		auto [w, v] = arr[i];
		//cout << "i=" << i << " w=" << w << " v=" << v << endl;
		for (int j = k; j > 0; j--)
		{
			if (j - w >= 0)
			{
				d[j] = max(d[j - w] + v, d[j]);
			}
			//cout << "j=" << j << " d[j]=" << d[j] << endl;
		}
	}
	cout << d[k];

	return 0;
}
