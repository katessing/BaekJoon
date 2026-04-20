#include <iostream>
#include <stack>

using namespace std;

int n;

int build[50];
int front[50];
int back[50];

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> build[i];
	}

	

	for (int i = 0; i < n; i++)
	{
		stack<double> fs;
		for (int j = i + 1; j < n; j++)
		{
			double slope = (static_cast<double>(build[j]) - static_cast<double>(build[i])) / (j - i);
			
			if (fs.empty() || fs.top() < slope)
			{
				fs.push(slope);
			}
		}
		front[i] = fs.size();
	}
	
	for (int i = n-1; i >= 0; i--)
	{
		stack<double> bs;
		for (int j = i - 1; j >= 0; j--)
		{
			double slope = (static_cast<double>(build[j]) - static_cast<double>(build[i])) / (i - j);
			
			if (bs.empty() || bs.top() < slope)
			{
				bs.push(slope);
			}
		}
		back[i] = bs.size();
		//cout << "Back See:" << count << endl;
	}

	int max_see = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = front[i] + back[i];
		if (sum > max_see)
		{
			max_see = sum;
		}
	}

	cout << max_see;
}
