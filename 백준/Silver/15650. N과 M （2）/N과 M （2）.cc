#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> visit;
vector<int> ans;
int N, M;

// 1234
// xx00
// 1 2 3 4
// 1 3

void dfs(int idx, int level)
{
	if (level == M)
	{
		for (int i : ans)
		{
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = idx + 1; i <= N; i++)
	{
		if (visit[i]) continue;
		visit[i] = true;
		ans[level] = i;
		dfs(i,level + 1);
		visit[i] = false;

	}
}

int main()
{
	cin >> N >> M;

	visit.resize(N+1);
	ans.resize(M);
	dfs(0, 0);

	return 0;
}
