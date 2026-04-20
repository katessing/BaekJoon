#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int map[1001][1001];
int visited[1001][1001];

int R, C;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

pair<int, int> origin;

queue<pair<int, int>> q;

void PrintVisited()
{
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			cout << visited[y][x] << ' ';
		}
		cout << '\n';
	}
}

void BFS()
{
	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;

			// 벽 cost = 0, 시작점도 visited = 0
			if (visited[ny][nx] == -1 && map[ny][nx] == 0)
			{
				visited[ny][nx] = 0;
			}
			else if (visited[ny][nx] == -1)
			{
				visited[ny][nx] = visited[y][x] + map[ny][nx];
				q.push({ ny, nx });
			}
		}
	}
	
}

int main()
{
	memset(map, 0xff, sizeof(map));
	memset(visited, 0xff, sizeof(visited));

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j <C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				origin = { i, j };
				visited[i][j] = 0;
			}
			else if (map[i][j] == 0)
			{
				visited[i][j] = 0;
			}
		}
	}

	q.push(origin);

	BFS();

	PrintVisited();

	return 0;
}