#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100001];
int parent[100001];
bool visited[100001];

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	parent[start] = start;


	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int a : adj[node])
		{
			if (visited[a]) continue;

			q.push(a);
			visited[a] = true;
			parent[a] = node;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	BFS(1);

	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << '\n';
	}
}