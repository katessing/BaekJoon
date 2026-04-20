#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

int N, M;
int V;

set<int> adj[1001];
bool visited[1001];

void DFS(int now)
{
	cout << now << ' ';

	if (adj[now].empty())
	{
		return;
	}

	for (int i : adj[now])
	{
		if (!visited[i])
		{
			visited[i] = true;
			DFS(i);
		}
	}
}

void BFS(int start)
{
	queue <int> q;
	q.push(start);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << ' ';

		for (int i : adj[cur])
		{
			if (!visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		adj[temp1].insert(temp2);
		adj[temp2].insert(temp1);
	}

	visited[V] = true;
	DFS(V);
	cout << '\n';

	memset(visited, 0, sizeof(visited));

	visited[V] = true;
	BFS(V);
}