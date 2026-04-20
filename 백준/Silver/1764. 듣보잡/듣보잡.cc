#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> n >> m;

	vector<string> heard(n);
	for (int i = 0; i < n; i++)
	{
		cin >> heard[i];
	}
	vector<string> listen(m);
	for (int i = 0; i < m; i++)
	{
		cin >> listen[i];
	}

	sort(heard.begin(), heard.end());
	sort(listen.begin(), listen.end());

	auto h = heard.begin();
	auto l = listen.begin();
	int count = 0;
	vector<string> ans(min(n, m));
	while (1)
	{
		if (*l == *h)
		{
			//cout << *l << '\n';
			
			ans[count++] = *l;
			l++;
			h++;
		}
		else if (*l < *h)
		{
			l++;
		}
		else
		{
			h++;
		}
		if (l == listen.end() || h == heard.end()) break;
	}
	cout << count << '\n';
	for (int i = 0; i <count;i++)
	{
		cout << ans[i] << '\n';
	}

	return 0;
}
