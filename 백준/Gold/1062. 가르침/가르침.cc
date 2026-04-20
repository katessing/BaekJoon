#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;
// 

bool alpha[26];
bool try_alp[26];
bool cand_alpha[26];

int n, k;

int Check(vector<bool[26]>& dict)
{
	int count = 0;
	for (auto page : dict)
	{
		bool include = true;
		for (int i = 0; i < 26; i++)
		{
			if (!page[i]) continue;
			
			if (!try_alp[i])
			{
				//cout << char('a' + i) << ' ' << page[i] << ' ' << try_alp[i] << endl;
				include = false;
			}
		}
		if (include) count++;
	}
	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	vector<string> word;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		word.push_back(input);
	}

	// string 단어를 순회한다.
	// bool 배열, 한칸에 각 문자에 대응, true로 기록한다
	// 이미 들어오는 조건 5개 문자는 alpha로 관리.
	// 그외에 추가 문자를 candid 벡터로 관리
	// k - 5 개만큼, 추가 가능
	// candid.size() 중 k - 5 의 숫자만큼 조합 순회를 통해
	// 체크 했을 때의 리턴값이 최대인것을 리턴한다.
	
	string suffix = "antatica";
	int num_suffix = 0;
	for (char c : suffix)
	{
		if (!alpha[c - 'a'])
		{
			alpha[c - 'a'] = true;
			num_suffix++;
		}
	}

	vector<char> candid;
	vector<bool[26]> dict(n);
	
	int idx = 0;
	for (string w : word)
	{
		auto al = dict[idx];
		for (char c : w)
		{
			al[c - 'a'] = true;
			if (!alpha[c - 'a'] && !cand_alpha[c-'a'])
			{
				candid.push_back(c);
				cand_alpha[c - 'a'] = true;
			}
		}
		idx++;
	}

	if (k < 5)
	{
		cout << 0;
		return 0;
	}
	else if (candid.size() < k - 5)
	{
		cout << n;
		return 0;
	}

	vector<bool> iter(candid.size());
	for (int i = 0; i < k - 5; i++)
	{
		iter[i] = true;
	}

	int ans_count = 0;
	do
	{
		memcpy(try_alp, alpha, sizeof(alpha));
		for (int i = 0; i < iter.size(); i++)
		{
			if (!iter[i]) continue;
			char c = candid[i];
			try_alp[c - 'a'] = true;
		}

		int temp = Check(dict);
		if (ans_count < temp) ans_count = temp;
	} while (prev_permutation(iter.begin(), iter.end()));

	cout << ans_count;
}