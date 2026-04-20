#include <iostream>

using namespace std;

int arr[1'000'001];
int n, m;

// 1 2 3
// 1 1 3

// 2 -> 1
// 

int Find(int a)
{
	if (arr[a] == a)
		return a;

	return arr[a] = Find(arr[a]);
}

bool Check(int a, int b)
{
	int par_a = Find(a);
	int par_b = Find(b);

	return par_a == par_b;
}

void Merge(int a, int b)
{
	// a -> b
	int par_a = Find(a);
	int par_b = Find(b);
	arr[par_a] = par_b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int op, a, b;
		cin >> op >> a >> b;

		if (op == 1)
		{
			// check same
			if (Check(a, b))
			{
				cout << "yes" << '\n';
			}
			else
			{
				cout << "no" << '\n';
			}
		}
		else if (op == 0)
		{
			// union
			Merge(a, b);
		}
	}
}