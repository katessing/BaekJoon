#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n, m;

int map[9][9];
int copy_map[9][9];
int visit[9][9];

vector<pair<int, int>> virus;
vector<pair<int, int>> space;
vector<int> space_index;
vector<bool> space_visit;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0,-1, 0, 1 };

int max_space = -1;

void BFS()
{
	queue<pair<int, int>> q;
	for (auto [y, x] : virus)
	{
		q.push({ y,x });
	}

	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

			if (copy_map[ny][nx] == 0)
			{
				copy_map[ny][nx] = 2;
				q.push({ ny, nx });
			}
		}
	}

}

int Calc()
{
	int count = 0;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (copy_map[y][x] == 0)
				count++;
		}
	}
	return count;
}

void Block()
{
	memcpy(copy_map, map, sizeof(map));
	for (int idx : space_index)
	{
		auto [y, x] = space[idx];
		copy_map[y][x] = 1;
	}
}

void DFS(int level, int num)
{
	if (level == 3)
	{
		Block();
		BFS();
		int count = Calc();
		if (max_space < count) max_space = count;
		return;
	}

	for (int i = num; i < space.size(); i++)
	{
		if (space_visit[i]) continue;
		space_visit[i] = true;
		space_index.push_back(i);
		DFS(level + 1, i + 1);
		space_visit[i] = false;
		space_index.pop_back();
	}
}

int main()
{
	cin >> n >> m;
	
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 2)
			{
				virus.push_back({ y,x });
			}
			else if (map[y][x] == 0)
			{
				space.push_back({ y,x });
			}
		}
	}

	space_visit.resize(space.size(), false);

	DFS(0, 0);
	cout << max_space;
}