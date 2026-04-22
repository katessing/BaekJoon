#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, k, l;

int map[101][101];
deque<pair<int, char>> command;

// 뱀을 어떻게 처리할거임?
// 머리, 꼬리로 나눌까??
// 머리 진행 command와 꼬리 진행 command를 구분..


pair<int, int> head = {1,1};
pair<int, int> tail;

deque <pair<int, int>> body;
// head와 queue로 관리? queue 사이즈는 처음에 0, 사과먹으면 1증가하는 개념
// 이동하면 queue를 pop, 사과 먹으면 skip
// 이동할 때 마다 머리 좌표를 queue에 넣기

int dx[4] = {1, 0, -1, 0};
int dy[4] = { 0, -1, 0, 1 };

int dir_idx = 0;

bool Wall()
{
	auto [y, x] = head;
	if (y < 1 || y > n || x < 1 || x > n)
		return true;
	return false;
}

bool Touch()
{
	// head가 몸통과 겹치는지 체크
	auto it = find(body.begin(), body.end(), head);
	return it != body.end();
}

void Move(bool& is_wall, bool& is_touch)
{
	auto [cy, cx] = head;
	int ny = cy + dy[dir_idx];
	int nx = cx + dx[dir_idx];

	body.push_back(head);
	head = { ny, nx };

	is_wall = Wall();
	is_touch = Touch();

	if (map[ny][nx] != 1)
	{ // no
		body.pop_front();
	}
	else
	{
		map[ny][nx] = 0;
	}
}

void Turn(int time)
{
	if (command.size() == 0) return;

	auto [nt, dir] = command.front();
	if (time != nt)
	{
		return;
	}

	if (dir == 'L')
	{
		dir_idx = (dir_idx + 4 + 1) % 4;
	}
	else
	{
		dir_idx = (dir_idx + 4 - 1) % 4;
	}
	command.pop_front();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int y, x;
		cin >> y >> x;
		// 사과 처리
		map[y][x] = 1;
	}
	
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int sec;
		char c;
		cin >> sec >> c;

		command.push_back({ sec, c });
	}
	sort(command.begin(), command.end());
	// L : (dir + 1)%4
	// R : (dir - 1)%4

	bool is_wall = false;
	bool is_touch = false;

	int time = 0;

	while (!is_wall && !is_touch)
	{
		time++;
		Move(is_wall, is_touch);
		Turn(time);
		//cout << "TWTD" << time << is_wall << is_touch << dir_idx << endl;
		//cout << "YXS" << head.first << head.second << body.size() << endl;
	}

	cout << time;
	return 0;
}