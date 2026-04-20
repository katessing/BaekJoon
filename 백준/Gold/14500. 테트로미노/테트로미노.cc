#include <iostream>

using namespace std;

int map[505][505];
bool visited[505][505];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int R, C;

int COST = 0;


// (x,y)
int Shape[][4][2] = {
	{{0, 0},{1, 0}, {2, 0}, { 1,1 }},
	{{0, 1},{1, 1}, {2, 1}, { 1,0 }},
	{{0, 0},{0, 1}, {0, 2}, { 1,1 }},
	{{1, 0},{1, 1}, {1, 2}, { 0,1 }}
};

void dfs(int x, int y, int cost, int size)
{
	int current_cost = cost + map[y][x];

	if (size == 4)
	{
		if (current_cost > COST) COST = current_cost;
		
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;

		if (!visited[ny][nx])
		{
			visited[ny][nx] = true;
			dfs(nx, ny, current_cost, size + 1);
			visited[ny][nx] = false;
		}
	}
}

int main()
{
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			visited[y][x] = true;
			dfs(x, y, 0, 1);
			visited[y][x] = false;
		}
	}


	for (int y = 0; y < R-1; y++)
	{
		for (int x = 0; x < C-2; x++)
		{
			for (int s = 0; s < 2; s++)
			{
				int cost = map[Shape[s][0][1] + y][Shape[s][0][0] + x]
					+ map[Shape[s][1][1] + y][Shape[s][1][0] + x]
					+ map[Shape[s][2][1] + y][Shape[s][2][0] + x]
					+ map[Shape[s][3][1] + y][Shape[s][3][0] + x];
				if (cost > COST) COST = cost;
			}
		}
	}

	for (int y = 0; y < R - 2; y++)
	{
		for (int x = 0; x < C - 1; x++)
		{
			for (int s = 2; s < 4; s++)
			{
				int cost = map[Shape[s][0][1] + y][Shape[s][0][0] + x]
					+ map[Shape[s][1][1] + y][Shape[s][1][0] + x]
					+ map[Shape[s][2][1] + y][Shape[s][2][0] + x]
					+ map[Shape[s][3][1] + y][Shape[s][3][0] + x];
				if (cost > COST) COST = cost;
			}
		}
	}

	cout << COST;
}