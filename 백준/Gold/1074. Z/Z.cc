#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ans = 0;

void divide(int n, int r, int c)
{
	int len = 1 << n;

	int is_down = 0;
	int is_right = 0;

	if (r >= len / 2)
	{
		is_down = 1;
		ans += len * len / 2;
	}

	if (c >= len / 2)
	{
		is_right = 1;
		ans += len * len / 4;
	}
		
	if (n == 1)
	{
		return;
	}

	divide(n - 1, r % (len / 2), c % (len / 2));
}

int main()
{
	int n, r, c;

	cin >> n >> r >> c;
	
	divide(n, r, c);

	cout << ans;

	return 0;
}