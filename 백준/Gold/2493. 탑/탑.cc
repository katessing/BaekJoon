#include <iostream>
#include <stack>

using namespace std;

int N;
stack<pair<int,int>> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;

		int ans = 0;
		while (!s.empty() && s.top().first <= temp)
		{
			s.pop();
		}

		if (!s.empty())
		{
			ans = s.top().second;
		}
		s.push({ temp, i });

		cout << ans << ' ';
	}
	return 0;
}