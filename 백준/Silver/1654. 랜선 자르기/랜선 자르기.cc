#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Check(const vector<int>& input, long long x)
{
	long long count = 0;
	for (int i : input)
	{
		count += i / x;
	}

	return count;
}

//int BinarySearch(function<int(const vector<int>&, int)> fun, int x)
//{
//
//}

int BinarySearch(const vector<int>& input, int x)
{
	long long start = 1;
	long long end = *max_element(input.begin(), input.end());
	long long ans = 0;
	while (start <= end)
	{
		long long mid = start + (end - start) / 2;
		long long value = Check(input, mid);
		if (value >= x)
		{
			ans = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
		
	}
	return ans;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k, n;

	cin >> k >> n;
	vector<int> line(k);

	for (int& l : line)
	{
		cin >> l;
	}

	cout << BinarySearch(line, n);

}