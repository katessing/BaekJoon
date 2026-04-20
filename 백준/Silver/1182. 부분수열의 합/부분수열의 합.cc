#include <iostream>
#include <vector>

using namespace std;

vector<int> series;

int n, s;
int ans_count = 0;

void DFS(int idx, int sum, int size)
{
	// 종료 조건
	// sum == s

	if (sum == s && size > 0)
	{
		ans_count++;
	}

	for (int i = idx; i < n; i++)
	{
		DFS(i + 1, sum + series[i], size+1);
	}
	
}

int main()
{
	cin >> n >> s;
	series.reserve(n);

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		series.push_back(input);
	}

	DFS(0, 0, 0);

	cout << ans_count;
}