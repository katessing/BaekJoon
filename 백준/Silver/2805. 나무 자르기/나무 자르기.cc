#include <iostream>
#include <vector>
using namespace std;

long long Cut(vector<int>& data, int height)
{
	long long sum = 0;

	for (int d : data)
	{
		if (d > height)
		{
			sum += (d - height);
		}
	}

	return sum;
}

int main()
{
	int n, m;

	cin >> n >> m;
	vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int start = 0;
	int end = 1'000'000'000;
	int mid;

	int max_height = 0;

	while (start <= end)
	{
		mid = start + (end - start) / 2;
		long long result = Cut(arr, mid);
		if (result < m)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
			if (mid > max_height) max_height = mid;
		}
	}
	
	cout << max_height;
	return 0;
}