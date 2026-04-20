#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int main()
{
	int n, m;
	cin >> n >> m;

	house.reserve(2 * n + 1);
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			cin >> map[y][x];

			if (map[y][x] == 2)
			{
				chicken.push_back({ y, x });
			}
			else if(map[y][x] == 1)
			{
				house.push_back({ y, x });
			}
		}
	}


	// 각각의 chicken 집에 대한 각 집의 거리를 계산
	// checken 집은 고정. 집에 대해서만 순회. 즉. 집과 같은 사이즈의 벡터 생성.
	// 배열이 낫나..?
	
	// chick idx -> cost vect
	vector<vector<int>> dist(chicken.size(), vector<int>(house.size(), 0)); 

	int ch_idx = 0;
	for (auto& vec : dist)
	{
		for (int i = 0; i < house.size(); i++)
		{
			// chicken -> ch_idx
			// house -> i = house index
			auto [cy, cx] = chicken[ch_idx];
			auto [hy, hx] = house[i];

			vec[i] = abs(cy - hy) + abs(cx - hx);
		}
		ch_idx++;
	}

	// chicken.size() 중 M개 조합으로 결과 뽑기 -> 그중 최소값만 가져가기

	vector<bool> select(chicken.size());
	for (int i = 0; i < m; i++)
	{
		select[i] = true;
	}

	sort(select.begin(), select.end());

	int min_sum = 1e9;
	
	do
	{
		int sum = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int temp = 1e9;
			for (int j = 0; j < select.size(); j++)
			{
				if (!select[j]) continue;

				if (temp > dist[j][i])
				{
					temp = dist[j][i];
				}
			}
			sum += temp;
		}
		if (min_sum > sum) min_sum = sum;
	} while (next_permutation(select.begin(), select.end()));

	cout << min_sum;
	return 0;
}