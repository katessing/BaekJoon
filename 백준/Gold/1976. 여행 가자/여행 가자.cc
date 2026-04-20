#include <iostream>

using namespace std;

int arr[201];

int Find(int x)
{
	if (arr[x] == x)
		return x;

	return arr[x] = Find(arr[x]);
}

void Union(int a, int b)
{
	int parent_a = Find(a);
	int parent_b = Find(b);

	arr[parent_b] = parent_a;
}

bool Check(int a, int b)
{
	return Find(a) == Find(b);
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		arr[i] = i;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int input;
			cin >> input;
			if (input)
			{
				Union(i, j);
			}
		}
	}

	int start;
	cin >> start;
	bool connect = true;
	for (int i = 1; i < m; i++)
	{
		int input;
		cin >> input;

		connect &= Check(start, input);
	}
	if (connect) cout << "YES";
	else cout << "NO";

	return 0;
}