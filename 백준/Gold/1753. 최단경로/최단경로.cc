#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;

int V;
int E;

constexpr int MAX = 0x3f3f3f3f;
constexpr int SIZE = 20000 + 1;

vector<pair<int,int>> adj[SIZE];

int dist[SIZE];

int main()
{
	memset(dist, 0x3F, sizeof(dist));

	int k;
	cin >> V >> E;
	cin >> k;

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[k] = 0;
	pq.push({ 0, k });
	while (!pq.empty())
	{
		auto [cw, cn] = pq.top();
		pq.pop();

		if (cw > dist[cn]) continue;

		for (auto p : adj[cn])
		{
			int next_weight = p.first;
			int next_node = p.second;

			if (cw + next_weight < dist[next_node])
			{
				dist[next_node] = cw + next_weight;
				pq.push({ dist[next_node], next_node });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		int value = dist[i];
		if (value == MAX)
		{
			cout << "INF" << '\n';
		}
		else
		{
			cout << value << '\n';
		}
	}
}