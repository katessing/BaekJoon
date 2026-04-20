#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class dual_q
{
	priority_queue <int, vector<int>, less<>> q_max;
	priority_queue <int, vector<int>, greater<>> store_max;
	priority_queue <int, vector<int>, greater<>> q_min;
	priority_queue <int, vector<int>, less<>> store_min;

public:
	void insert(int input);
	void del(int value);
	int result(int& max, int& min);
	void clear();
};

void dual_q::insert(int input)
{
	q_max.push(input);
	q_min.push(input);
}

void dual_q::del(int value)
{
	if (q_max.empty()) return;

	if (value == 1) // del max 
	{
		int temp = q_max.top();
		q_max.pop();
		store_max.push(temp);
	}
	else if (value == -1) // del min
	{
		int temp = q_min.top();
		q_min.pop();
		store_min.push(temp);
	}

	while (!q_min.empty() && !store_max.empty() && q_min.top() == store_max.top())
	{
		q_min.pop();
		store_max.pop();
	}

	while (!q_max.empty() && !store_min.empty() && q_max.top() == store_min.top())
	{
		q_max.pop();
		store_min.pop();
	}
	
	// try to avoid InvalidNextSize
	//if (q_min.empty() || q_max.empty())
	//{
	//	clear();
	//}
}

void dual_q::clear()
{
	while (!q_min.empty()) q_min.pop();
	while (!q_max.empty()) q_max.pop();
	while (!store_min.empty()) store_min.pop();
	while (!store_max.empty()) store_max.pop();
}

int dual_q::result(int& max, int& min)
{
	max = 0; min = 0;
	if (q_max.empty()) return 1;

	max = q_max.top();
	min = q_min.top();
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		dual_q dq;
		for (int j = 0; j < n; j++)
		{
			char c;
			int num;
			cin >> c >> num;
			if (c == 'I')
			{
				dq.insert(num);
			}
			else if (c == 'D')
			{
				dq.del(num);
			}
		}

		int max, min;
		if (dq.result(max, min))
		{
			cout << "EMPTY" << '\n';
		}
		else
		{
			cout << max << ' ' << min << '\n';
		}
	}
}