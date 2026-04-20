#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	unordered_map <int, string> str_map;
	unordered_map <string, int> int_map;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		str_map.insert({ i + 1, input });
		int_map.insert({ input, i + 1 });
	}

	for (int i = 0; i < m; i++)
	{
		string input;
		cin >> input;
		if (isdigit(input[0]))
		{
			int num = stoi(input);
			cout << str_map.at(num) << '\n';
		}
		else
		{
			cout << int_map.at(input) << '\n';
		}
	}

	return 0;
}