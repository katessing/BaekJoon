#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[21][21];
int N;

// 재귀로 참조해야함. visted 배열이 하나 있어야함.
// 백 트래킹으로.
// 인자는 1개? 2개? depth 필수. now는? dfs하면서 선택된 값을 어떻게 저장함?
// 전역 vector 따로 두고? 근데 visited 배열이 그 역할을 할거같은데..
// 반대 편 정보는?
bool visited[21];

int min_diff = 1e9;

void dfs(int idx, int depth)
{
	if (depth == N / 2)
	{
		// cost 계산
		// start
		vector<int> start;
		vector<int> link;
		
		for (int i = 1; i <= N; i++)
		{
			if (visited[i]) start.push_back(i);
			else link.push_back(i);
		}

		int sum_start = 0;
		int sum_link = 0;

		for (int i = 0; i < N / 2; i++)
		{
			for (int j = 0; j < N / 2; j++)
			{
				if (i == j) continue;
				//arr[i][j]
				sum_start += arr[start[i]][start[j]];
				sum_link += arr[link[i]][link[j]];
			}
		}

		// diff
		int diff = abs(sum_start - sum_link);

		// update min diff
		if (min_diff > diff) min_diff = diff;
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (idx >= i) continue;
		if (visited[i]) continue;

		visited[i] = true;
		dfs(i, depth + 1);
		visited[i] = false;
	}
}


int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		visited[i] = true;
		dfs(i, 1);
		visited[i] = false;
	}

	cout << min_diff;
}