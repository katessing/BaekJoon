#include <iostream>
#include <stack>

using namespace std;

int N;
const int SIZE = 80'000;
int H[SIZE] = { 0, };

int main()
{
	cin >> N;
	stack<int> s;
	long long count = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> H[i];
	}
	
	for (int i = 0; i < N; i++)
	{
		while (!s.empty() && s.top() <= H[i])
		{
			s.pop();
		}
		count += s.size();
		s.push(H[i]);
	}
	
	cout << count;

	return 0;
}