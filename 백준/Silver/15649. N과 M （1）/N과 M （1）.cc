#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ser;
vector<int> visit;
vector<int> ans;
int N, M;

// 1234
// xx00
// 1 2 3 4
// 1 3

void dfs(int level)
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

	for (int i = 0; i < ser.size(); i++)
	{
		if (visit[i]) continue;
		visit[i] = true;
		ans.push_back(i+1);
		dfs(level + 1);
		visit[i] = false;
		ans.erase(ans.end() - 1, ans.end());
	}
}

int main()
{
	cin >> N >> M;

	ser.reserve(N);
	visit.resize(N);
	for (int i = 0; i < N; i++)
	{
		ser.push_back(i + 1);
	}

	dfs(0);


	return 0;
}
