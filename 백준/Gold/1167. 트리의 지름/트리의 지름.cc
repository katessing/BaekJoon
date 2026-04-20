#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

constexpr int SIZE = 100'001;
int visited[SIZE];
//int parent[SIZE][2];
vector<pair<int, int>> adj[SIZE];

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (auto [n, c] : adj[node])
		{
			if (visited[n]) continue;

			q.push(n);
			visited[n] = visited[node] + c;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int start, node, cost;
		cin >> start;
		cin >> node;
		while (node != -1)
		{
			cin >> cost;
			adj[start].push_back({ node, cost });
			cin >> node;
		}
	}

	BFS(1);
	int max_cost = 0;
	int max_node = 0;
	for (int i = 2; i <= n; i++)
	{
		if (max_cost < visited[i])
		{
			max_cost = visited[i];
			max_node = i;
		}
	}

	memset(visited, 0, sizeof(visited));

	BFS(max_node);
	max_cost = 0;
	max_node = 0;
	for (int i = 1; i <= n; i++)
	{
		if (max_cost < visited[i])
		{
			max_cost = visited[i];
			max_node = i;
		}
	}

	cout << max_cost - 1;
}