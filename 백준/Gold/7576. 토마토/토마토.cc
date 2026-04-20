#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = { 1, 0, -1, 0 };

int map[1001][1001];
int day[1001][1001];

int main()
{
	memset(map, 0xff, sizeof(map));
	memset(map, 0xff, sizeof(map));
	queue<pair<int, int>> q;
	
	int m,n;
	cin >> m >> n;
	
	int input_grown = 0;
	int total = 0;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			int temp;
			cin >> temp;
			map[y][x] = temp;
			
			if (temp == 1)
			{
				q.push({ y, x });
				day[y][x] = 0;
				input_grown++;
				total++;
			}
			else if (temp == 0)
			{
				total++;
			}
		}
	}
		
	int max_day = 0;
	int grow_num = 0;

	if (total == input_grown)
	{
		cout << 0;
		return 0;
	}

	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

			if (map[ny][nx] == 0)
			{
				map[ny][nx] = 1;
				day[ny][nx] = day[y][x] + 1;
				if (max_day < day[ny][nx])
					max_day = day[ny][nx];
				q.push({ ny, nx });
				grow_num++;
				//cout << grow_num << ", " << ny << ", " << nx << endl;
			}
		}
	}

	//cout << total <<", " << grow_num << ", " << input_grown;

	if (total == grow_num + input_grown)
	{
		cout << max_day;
	}
	else
	{
		cout << -1;
	}
	return 0;
}