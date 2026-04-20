#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1001];
int visited[1001];


void bfs(int start)
{
	queue<int> q;
	
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		
		for (int next : adj[node])
		{
			if (!visited[next] )
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int count = 0;
	for (int i = 1; i < n + 1; i++)
	{
		if (!visited[i])
		{
			bfs(i);
			count++;
		}
	}
	cout << count;
}
