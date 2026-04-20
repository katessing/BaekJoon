#include <iostream>

using namespace std;

string oper[] = {"add", "remove", "check", "toggle", "all", "empty"};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m;
	cin >> m;
	
	int s=0;

	for (int i = 0; i < m; i++)
	{
		string op;
		int num;
		cin >> op;
		if (op != oper[4] && op != oper[5])
		{
			cin >> num;
			num--;
		}
		
		if (op == oper[0])
		{
			s |= (1 << num);
		}
		else if (op == oper[1])
		{
			int temp = ~(1 << num);
			s &= temp;
		}
		else if (op == oper[2])
		{
			int temp = s & (1 << num);
			if (temp > 0)
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (op == oper[3])
		{
			s ^= (1 << num);
		}
		else if (op == oper[4])
		{
			// 1111 = 0xf
			// 0111 = 0x7
			// 1111 1111 1111 1111 1111 = 0x7ffff
			s = 0x0fffff; 
		}
		else if (op == oper[5])
		{
			s = 0;
		}
	}

	return 0;
}