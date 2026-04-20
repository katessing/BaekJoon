#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> ladder;
vector<pair<int, int>> snake;

int visited[101];
int board[101];

void BFS(int start, int end)
{
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++)
		{
			int node = cur + i;
			if (node > end) continue;
			int next_node = board[node];
			if (!visited[next_node])
			{
				visited[next_node] = visited[cur] + 1;
				q.push(next_node);
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= 100; i++)
	{
		board[i] = i;
	}

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a] = b;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a] = b;
	}

	BFS(1, 100);
	int ans = visited[100] - 1;
	cout << ans;
}