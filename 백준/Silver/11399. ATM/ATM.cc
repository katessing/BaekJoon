#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(begin(arr), begin(arr) + n);

	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		int j = n - i;
		sum += arr[i] * j;
	}

	cout << sum;
	return 0;
}