#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

priority_queue <int, vector<int>, greater<int>> pq;
vector<pair<int, int>> lec;


int main()
{
	int n;
	cin >> n;
	lec.resize(n);
	for (int i = 0; i < n; i++)
	{
		int s, t;
		cin >> s >> t;
		lec[i] ={ s, t };
	}

	sort(begin(lec), end(lec));
	
	for (auto [s, t] : lec)
	{
		if (!pq.empty() && pq.top() <= s)
		{
			pq.pop();
		}
		pq.push(t);
	}
	
	cout << pq.size();
	return 0;
}