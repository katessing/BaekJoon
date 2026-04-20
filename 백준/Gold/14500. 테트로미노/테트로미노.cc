#include <iostream>

using namespace std;

int map[500][500];

// 2 x 3 - 2
// 3 x 2 - 2
// 2 x 2
// 1 x 4
// 4 x 1

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
		}
	}

	int sum = 0;
	for (int i = 0; i < r - 1; i++)
	{
		for (int j = 0; j < c - 1; j++)
		{
			int area = map[i][j] + map[i+1][j] + map[i][j+1] + map[i+1][j+1];
			if (sum < area) sum = area;
		}
	}
	
	for (int i = 0; i < r - 3; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int area = map[i][j] + map[i + 1][j] + map[i+2][j] + map[i + 3][j];
			if (sum < area) sum = area;
		}
	}
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c - 3; j++)
		{
			int area = map[i][j] + map[i][j+1] + map[i][j + 2] + map[i][j + 3];
			if (sum < area) sum = area;
		}
	}
	
	//[][]
	//[][]
	//[][]
	//3 x 2
	for (int i = 0; i < r - 2; i++)
	{
		for (int j = 0; j < c - 1; j++)
		{
			int area = map[i][j] + map[i+1][j] + map[i+2][j]
				+ map[i][j+1] + map[i + 1][j + 1] + map[i + 2][j + 1];
			int shape = area - map[i][j] -map[i+1][j];
			if (sum < shape) sum = shape;
			shape = area - map[i+1][j] -map[i+2][j];
			if (sum < shape) sum = shape;
			shape = area - map[i][j+1] -map[i + 1][j + 1];
			if (sum < shape) sum = shape;
			shape = area - map[i + 1][j + 1] -map[i + 2][j + 1];
			if (sum < shape) sum = shape;
			shape = area - map[i][j] -map[i+2][j];
			if (sum < shape) sum = shape;
			shape = area - map[i][j+1] -map[i+2][j + 1];
			if (sum < shape) sum = shape;
			shape = area - map[i][j] -map[i + 2][j + 1];
			if (sum < shape) sum = shape;
			shape = area - map[i][j+1] -map[i+2][j];
			if (sum < shape) sum = shape;
		}
	}

	//[][][]
	//[][][]
	//yx
	//2 x 3
	for (int i = 0; i < r - 1; i++)
	{
		for (int j = 0; j < c - 2; j++)
		{
			int area = map[i][j] + map[i][j + 1] + map[i][j + 2]
				+ map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
			//[x][x][]
			//[][][]
			int shape = area - map[i][j] - map[i][j + 1];
			if (sum < shape) sum = shape;
			//[][x][x]
			//[][][]
			shape = area - map[i][j+1] -map[i][j + 2];
			if (sum < shape) sum = shape;
			//[][][]
			//[x][x][]
			shape = area - map[i+1][j] -map[i+1][j + 1];
			if (sum < shape) sum = shape;
			//[][][]
			//[][x][x]
			shape = area - map[i + 1][j+1] -map[i + 1][j + 2];
			if (sum < shape) sum = shape;
			//[x][][x]
			//[][][]
			shape = area - map[i][j] -map[i][j + 2];
			if (sum < shape) sum = shape;
			//[][][]
			//[x][][x]
			shape = area - map[i+1][j] -map[i+1][j + 2];
			if (sum < shape) sum = shape;
			//[x][][]
			//[][][x]
			shape = area - map[i][j] -map[i + 1][j + 2];
			if (sum < shape) sum = shape;
			//[][][x]
			//[x][][]
			shape = area - map[i+1][j] -map[i][j + 2];
			if (sum < shape) sum = shape;
		}
	}

	cout << sum;
}