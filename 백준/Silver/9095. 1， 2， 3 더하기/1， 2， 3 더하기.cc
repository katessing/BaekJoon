#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int Combi(int n)
{
	int loop3 = n / 3;
	vector<tuple<int, int, int>> num_set;

	for (int a = 0; a <= loop3; a++)
	{
		// a = 3의 개수
		int remain = n - 3 * a;
		int loop2 = remain / 2;
		for (int b = 0; b <= loop2; b++)
		{
			// b = 2의 개수
			int remain2 = remain - 2 * b;
			int c = remain2;
			// c = 1의 개수
			num_set.push_back({ a,b,c, });
		}
	}

	int ans = 0;
	for (auto [a, b, c] : num_set)
	{
		int num = a + b + c;
		vector<int> series;
		series.reserve(num);
		for (int i = 0; i < c; i++) series.push_back(1);
		for (int i = 0; i < b; i++) series.push_back(2);
		for (int i = 0; i < a; i++) series.push_back(3);
		
		do
		{
			ans++;
		} while (next_permutation(series.begin(), series.end()));

	}

	return ans;
}


int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int input;
		cin >> input;
		cout << Combi(input) << '\n';
	}
}