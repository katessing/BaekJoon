#include <iostream>

using namespace std;

int map[128][128];

int blue_count = 0;
int white_count = 0;

void divide(int xstart, int ystart, int size)
{
	// map, xstart, xend, ystart, yend
	// check area same
	//cout << xstart << ", " << ystart << ", " << size<< endl;
	if (size < 1)
	{
		return;
	}

	int color = map[ystart][xstart];
	bool unique = true;
	for (int y = ystart; y < ystart + size; y++)
	{
		for (int x = xstart; x < xstart + size; x++)
		{
			if (map[y][x] != color)
			{
				unique = false;
				break;
			}
		}
	}

	// if same return and b/w count++
	if (unique)
	{
		if (color) blue_count++;
		else white_count++;
	}
	// if not divide
	else
	{
		int next_size = size / 2;
		divide(xstart, ystart, next_size);
		divide(xstart + next_size, ystart, next_size);
		divide(xstart, ystart + next_size, next_size);
		divide(xstart + next_size, ystart + next_size, next_size);
	}
}

int main()
{
	int n;
	cin >> n;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> map[y][x];
		}
	}
	divide(0,0,n);
	cout << white_count << '\n';
	cout << blue_count << '\n';
}
