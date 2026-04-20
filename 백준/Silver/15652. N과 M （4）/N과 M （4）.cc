#include <iostream>
#include <vector>

using namespace std;


int m, n;
vector<int> dv;

void DFS(int num, int level)
{
	if (level == m)
	{
		for (int d : dv)
			cout << d << ' ';
		cout << '\n';
		return;
	}

	for (int i = num; i <= n; i++)
	{
		dv.push_back(i);
		DFS(i, level + 1);
		dv.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	DFS(1, 0);

	return 0;
}