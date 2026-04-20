#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue <unsigned int, vector<unsigned int>, greater<>> q;
	for (int i = 0; i < n; i++)
	{
		unsigned int input;
		cin >> input;
		if (input == 0)
		{
			if (q.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else
		{
			q.push(input);
		}
	}
}