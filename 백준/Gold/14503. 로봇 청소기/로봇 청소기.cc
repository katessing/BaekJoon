#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 1. if check(pos) == clear? clean() : nothing
// 2. checkAround ? all clean -> check can goback? -> goback -> #1
//					find not clean -> turn counterclockwise

enum dir { N, E, S, W };
vector<int> dx = { 0, 1, 0, -1 };
vector<int> dy = { -1, 0, 1, 0 };

int nc = 0;
int wall = 1;

int n, m;

bool OOB(int r, int c)
{
	if (r < 0 || r > n-1 || c < 0 || c > m - 1)
		return true;
	return false;
}

bool CheckAround(vector<vector<int>>& map, int r, int c)
{
	//bool is_find = false;
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dy[i];
		int nc = c + dx[i];
		
		if (OOB(r, c)) continue;

		if (map[nr][nc] == 0)
		{
			//cout << "Find Not Clean:" << nr << nc << endl;
			return true;
		}
	}
	//cout << "All Clean:" << r << c << endl;
	return false;
}

int main()
{

	cin >> n >> m;
	int r0, c0, d0;
	cin >> r0 >> c0 >> d0;

	vector<vector<int>> geo_map(n);

	for (int r = 0; r < n; r++)
	{
		geo_map[r].resize(m);
		for (int c = 0; c < m; c++)
		{
			int value;
			cin >> value;
			geo_map[r][c] = value;
		}
	}

	int count = 0;

	int r = r0;
	int c = c0;
	int d = d0;

	while(1)
	{
		// #1
		if (geo_map[r][c] == 0) // clean
		{
			count++;
			geo_map[r][c] = 2;
			//cout << "Clean:" << r << c << d << count << endl;
		}

		if (CheckAround(geo_map, r, c))
		{
			// find not clean->turn counterclockwise
			for (int i = 0; i < 4; i++)
			{
				int ccw = (d + 4 - 1) % 4;
				int tr = r + dy[ccw];
				int tc = c + dx[ccw];
				//cout << ccw << tr << tc << geo_map[tr][tc] << endl;
				if (geo_map[tr][tc] == 0)
				{
					// not clean
					r = tr;
					c = tc;
					d = ccw;
					//cout << "Turn And Go:" << r << c << d << count << endl;
					break;
				}
				else
				{
					// clean or wall
					// ccw
					d = ccw;
					//cout << "CCW:" << r << c << d << count << endl;
				}
			}
			
		}
		else
		{
			// #2. checkAround ? all clean -> check can goback? -> goback -> #1
			int back = (d + 2) % 4;
			int tr = r + dy[back];
			int tc = c + dx[back];
			bool can_go = !OOB(tr, tc);
			if (can_go && geo_map[tr][tc] != 1) // check can go back?
			{
				r = tr;
				c = tc;
				//cout << "Goback:" << r << c << d << count << endl;
			}
			else
			{
				//block
				//cout << "block:" << r << c << d << count << endl;
				break;
			}
		}

	}

	cout << count << endl;

	return 0;
}