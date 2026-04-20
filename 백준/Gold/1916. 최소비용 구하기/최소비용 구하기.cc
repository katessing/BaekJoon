#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int m;

int node[1001];
vector<pair<int, int>> bus[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(begin(node), end(node), 1e9);
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		bus[start].push_back({ cost, end });
	}

	int start, end;
	cin >> start >> end;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	node[start] = 0;
	pq.push({0, start});
	while (!pq.empty())
	{
		auto [cur_cost, cur] = pq.top();
		pq.pop();

		if (node[cur] < cur_cost) continue;

		for (int i = 0; i < bus[cur].size(); i++)
		{
			auto p = bus[cur][i];
			int cost = p.first;
			int next = p.second;

			if (node[next] > cur_cost + cost)
			{
				node[next] = node[cur] + cost;
				pq.push({ node[next], next });
			}
		}
	}

	cout << node[end];
}