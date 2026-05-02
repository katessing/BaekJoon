#include <iostream>
#include <vector>

using namespace std;

// R 빼기, B는 안됨
// 4개 방향의 중력을 가하는데 -> 어떤 알고리즘
// 동시에 빠져도 실패
// 구슬이 더이상 움직이지 않을때까지 기울임
// 최소 몇번

// 3<= <=10
// .: empty
// #: wall
// 0: hole
// R: red
// B: b

int n, m;

char map[10][10];

vector<vector<pair<int, int> > > ball; // red,blue
pair<int, int> hole;

// 4개 방향의 중력을 가하는데
// DFS로 매번 찾기? - backtracking?
// 10번 넘기면 out

// 기울일때 움직임은??
// #에 막힐때까지 움직임
// 다른 색 공이랑 붙어버리면?
// R.B 일때
// 왼쪽이면 왼쪽공을 먼저, 오른쪽이면 오른쪽 공을 먼저..

// 원본 맵을 가지고 있으면서 복사해서 맵을 쓰자?
// backtracking 하면 이전 상태 복원이 되나?
// level 당 맵을 다 기억해야함....
// map을 최대 10개 가지고 있어야하나?
// 3중 배열 [10][10][10]은?
// vector<char[10][10]> 구조는 되나?


// 맵을 매번 수정하는건 너무 비효율...
// 공의 좌표만 알면 되지 않아?
// 백트래킹도 더 쉬울듯 - 메모리상 이점
// 공의 자료구조는 뭘로?
// 벡터는 필요함
// 문제는 blue -> red / red -> blue 순서를 반복문으로 돌리려면 벡터에 두 공을 다 넣는게..
// 2차원 벡터같은게 나을지도
// 

// 조합느낌이라서 DFS로 했는데
// BFS는? 현 구조에서는 불가능한 느낌.. 모든 상태를 다 알고 있어야함.
// 빨리 끝낼 수는 있음. 최적해 보장함
// DFS는 끝까지 돌려야함
// 근데 4^10인데.. 이거 되나??
// 시간을 아끼기 위해서 Tilt했을때와 Tilt 이후가 같다면.. 이 루트는 의미가 없는거아님?


int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int min_try = 20;

int Tilt(int level, int dir)
{
	bool blue_first = false;
	bool success = false;
	switch (dir)
	{
	case 0://E
		if (ball[level][1].second > ball[level][0].second)
		{
			blue_first = true;
		}
		break;
	case 1://N
		if (ball[level][1].first < ball[level][0].first)
		{
			blue_first = true;
		}
		break;
	case 2://W
		if (ball[level][1].second < ball[level][0].second)
		{
			blue_first = true;
		}
		break;
	case 3://S
		if (ball[level][1].first > ball[level][0].first)
		{
			blue_first = true;
		}
		break;
	}
	
	//cout << "DIR:" << dir << ", " << blue_first << endl;

	for (int i = 0; i < 2; i++)
	{
		int idx = i ^ blue_first;

		int y = ball[level][idx].first;
		int x = ball[level][idx].second;

		pair<int, int> another = ball[level + i][idx ^ 1];

		//pair<int, int> before = ball[level][idx];
		while (1)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			// 벽에 막힘
			if (map[ny][nx] == '#') break;
			// 공에 막힘
			
			if (ny == another.first && nx == another.second) break;
			// 구멍에 빠짐
			if (map[ny][nx] == 'O')
			{
				if (idx == 1) // 파란공 빠짐
				{
					return -1;
				}
				else
				{
					// 빨간 공 구멍에 빠진 상태
					y = -1;
					x = -1;
					success = true;
					break;
				}
			}
			y = ny;
			x = nx;
		}
		ball[level + 1][idx].first = y;
		ball[level + 1][idx].second = x;

		//cout << idx << "X:" << x << ",Y:" << y << endl;
	}

	if (success)
	{
		int num = level + 1;
		if (min_try > num) min_try = num;
		return 1;
	}


	return 0;
}

void DFS(int level, int prev_dir)
{
	//cout << level << endl;

	if (level == 10 || level >= min_try) // 최소값이상으로 파고들 이유없음
	{
		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		if (level > 0 && (prev_dir == i || prev_dir == (i ^ 2)))
			continue;

		ball.push_back(vector<pair<int, int>>(2));
		int ret = Tilt(level, i);
		if (ret == 1)
		{
			ball.pop_back();
			return;
		}
		else if (ret == -1)
		{
			ball.pop_back();
			continue;
		}
		// Tilt 전후의 위치 비교
		// pair는 == 비교되나?
		if (ball[level][0] == ball[level + 1][0] && ball[level][1] == ball[level + 1][1])
		{
			ball.pop_back();
			continue;
		}

		DFS(level + 1, i);
		// back
		ball.pop_back();

	}
}


int main()
{
	cin >> n >> m;

	ball.push_back(vector<pair<int, int>>(2));
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			char ch;
			cin >> ch;
			map[y][x] = ch;
			if (ch == 'B')
			{
				ball[0][1] = {y, x};
				map[y][x] = '.';
			}
			else if (ch == 'R')
			{
				ball[0][0] = { y, x };
				map[y][x] = '.';
			}
		}
	}

	DFS(0, 0);
	if (min_try == 20)
	{
		min_try = -1;
	}
	cout << min_try;
	return 0;
}