#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int map[20][20];
int visit[20][20];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n;

pair<int, int> shark_pos;
int shark_size = 2;
int shark_eat = 0;


void BFS(pair<int, int> pos)
{	
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;
	q.push(pos);
	auto [y, x] = pos;
	visit[y][x] = 1;

	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visit[ny][nx] || map[ny][nx] > shark_size) continue;
			q.push({ ny,nx });
			visit[ny][nx] = visit[y][x] + 1;
		}
	}
}

int SearchMin(pair<int, int>& pos)
{
	int min_cost = 1e9;
	bool find = false;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (map[y][x] > 0 && map[y][x] < shark_size && min_cost > visit[y][x] && visit[y][x])
			{
				//cout << "Y:" << y << "X:"  << x << endl;
				min_cost = visit[y][x];
				pos = { y, x };
				find = true;
			}
		}
	}

	return find;
}

int main()
{
	
	cin >> n;
	int time = 0;
	int fish_num = 0;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			int input;
			cin >> input;
			
			if (input == 9)
			{
				shark_pos = { y, x };
			}
			else if (input > 0)
			{
				map[y][x] = input;
				fish_num++;
			}
		}
	}

	if (fish_num == 0)
	{
		cout << 0;
		return 0;
	}

	//  
	// 1. BFS로 물고기와의 거리를 계산 (크기 같은 물고기까지만 지나감)(map에 거리 기록)
	// 2. 위에 있는 것 -> 왼쪽 우선 (map 순회하면서 같은 값은 업데이트 하지 않음?)
	// 3. 물고기를 먹고, shark 위치 갱신, 크기 갱신

	while (fish_num > 0)
	{
		BFS(shark_pos);
		//cout << "BFS done" << endl;
		pair<int, int> pos;
		if (!SearchMin(pos))
		{
			//cout << "No Fish to eat" << endl;
			break;
		}
		//cout << "Find Fish" << endl;
		// eat
		int y = pos.first;
		int x = pos.second;
		time += (visit[y][x] - 1);
		map[y][x] = 0;
		shark_pos = pos;
		shark_eat++;
		fish_num--;
		if (shark_eat == shark_size)
		{
			shark_size++;
			shark_eat = 0;
		}
	}

	cout << time;
}