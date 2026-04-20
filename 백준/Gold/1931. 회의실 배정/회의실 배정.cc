#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// d[0][1][2][3][4][5]
// 4, 5, 6, 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> time;

	time.reserve(n);

	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;
		time.push_back({ e, s }); // end, start
	}

	sort(begin(time), end(time));

	vector<pair<int, int>> room; // end, count

	int count = 0;
	int end = 0;

	for (auto t : time)
	{
		if (end <= t.second)
		{
			end = t.first;
			count++;
		}
	}

	cout << count;
}