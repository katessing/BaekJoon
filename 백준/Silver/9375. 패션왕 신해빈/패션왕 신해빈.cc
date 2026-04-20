#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, loop;
	cin >> loop;
	
	for (int l = 0; l < loop; l++)
	{
		cin >> n;
		unordered_map<string, vector<string>> um;
		set<string> ceteg_set;

		for (int i = 0; i < n; i++)
		{
			string cloth, categ;
			cin >> cloth >> categ;

			um[categ].push_back(cloth);
			ceteg_set.insert(categ);
		}

		int result = 1;
		for (string cat : ceteg_set)
		{
			result *= (um[cat].size() + 1);
		}
		result -= 1;
		cout << result << '\n';
	}

	return 0;
}
