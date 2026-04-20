#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& map, vector<vector<int>>& visit, pair<int, int> coord, int count);

const int max_size = 51;
//int map[max_size][max_size] = {0,};

int dx[4] = {1, 0, -1, 0}; // E, N, W, S
int dy[4] = { 0, -1, 0, 1 };

int limitx;
int limity;

int traverse(vector<vector<int>>& map, vector<vector<int>>& visit)
{
	int count = 0;
	
	for (int y = 0; y < limity; y++)
	{
		for (int x = 0; x < limitx; x++)
		{
			if (map[y][x] && visit[y][x] == 0)
			{
				bfs(map, visit, make_pair(y,x), ++count);
			}
		}
	}
	return count;
}

void bfs(vector<vector<int>>& map, vector<vector<int>>& visit, pair<int,int> coord, int count)
{
	queue<pair<int, int>> q;

	int y = coord.first;
	int x = coord.second;

	q.push(coord);
	visit[y][x] = count;
	while (!q.empty())
	{
		pair<int,int> nc = q.front();
		q.pop();
		y = nc.first;
		x = nc.second;
		map[y][x] = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < limitx && ny >= 0 && ny < limity)
			{
				if (map[ny][nx] && visit[ny][nx] == 0)
				{
					q.push(make_pair(ny, nx));
					visit[ny][nx] = count;
				}
			}
		}
	}
}

int main()
{
	int t;
	int m, n; // n x m
	int k; // 1<= k <=2500. regions

	cin >> t;
	for (int j = 0; j < t; j++)
	{

		cin >> m >> n >> k;
		limitx = m;
		limity = n;
		vector<vector<int>> map(n, vector<int>(m, 0));
		vector<vector<int>> visit(n, vector<int>(m, 0));
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		cout << traverse(map, visit) << endl;
	}
	

	return 0;
}
