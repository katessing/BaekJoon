#include <iostream>

using namespace std;

int arr[100'001];
int sum[100'001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = 0; i < m; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		cout << sum[num2] - sum[num1 - 1] << '\n';
	}

}