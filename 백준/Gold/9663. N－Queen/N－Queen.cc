#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;

int map[15][15];

int ans = 0;

int dx[4] = { 1, -1, -1, 1 };
int dy[4] = { -1, -1, 1, 1 };

vector<pair<int, int>> queen;

bool Valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;
	return true;
}

bool Check(int x, int y)
{
	for (auto [qy, qx] : queen)
	{
		if (qy == y) return false;
		if (qx == x) return false;
		int dist_x = abs(qx - x);
		int dist_y = abs(qy - y);
		if (dist_x == dist_y) return false;
	}

	return true;
}


void DFS(int level, int index)
{
	if (level == n)
	{
		ans++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!Check(i, level)) continue;
		
		queen.push_back({ level, i });
		map[level][i] = 1;
		DFS(level + 1, i + 1);

		queen.pop_back();
		map[level][i] = 0;
	}
}

int main()
{
	cin >> n;

	DFS(0, 0);
	cout << ans;
}