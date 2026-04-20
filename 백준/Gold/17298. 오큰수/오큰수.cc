#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> d;
	stack<int> s;
	d.resize(n);

	for (int  i = 0; i < n; i++)
	{
		cin >> d[i];
	}

	for (auto it = rbegin(d); it != rend(d); it++)
	{
		int cd = *it;
		while (!s.empty() && s.top() <= cd)
		{
			s.pop();
		}

		if (s.empty())
		{
			*it = -1;
		}
		else
		{
			*it = s.top();
		}
		s.push(cd);
	}

	for (int i : d)
	{
		cout << i << ' ';
	}


	return 0;
}