#include <iostream>

using namespace std;

int map[501][501];
int Y, X, B;

int SetLevel(int level)
{
	int time = 0;
	int dig = 0;
	int pour = 0;

	if (level < 0) return -1;

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (map[y][x] > level)
			{
				dig += (map[y][x] - level);
			}
			else if (map[y][x] < level)
			{
				pour += (level - map[y][x]);
			}
		}
	}

	time = dig * 2 + pour;
	int sand = pour - dig;
	if (B < sand)
		return -1;
	else
		return time;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> Y >> X >> B;

	int min_level = 257;
	int max_level = -1;

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			cin >> map[y][x];
			if (map[y][x] > max_level)
			{
				max_level = map[y][x];
			}
			if (map[y][x] < min_level)
			{
				min_level = map[y][x];
			}
		}
	}

	int min_time = 1e9;
	int ans_level;
	for (int level = min_level; level <= max_level; level++)
	{
		int time = SetLevel(level);
		if (time != -1 && time < min_time)
		{
			min_time = time;
			ans_level = level;
		}
		else if(time != -1 && time == min_time && level > ans_level)
		{
			ans_level = level;
		}
	}

	cout << min_time << ' ' << ans_level;

}