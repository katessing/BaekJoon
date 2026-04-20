#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> collect;

// 오름차순으로 이루어짐
// 한개의 모음과 2개의 자음은 포함해야함.
// 조합으로 붙여나가는거임. DFS로
// l개만큼만 탐색
// 암호를 직접 출력해야함. 즉 모으고 있다가 한번에 출력해야함.
// 재귀함수에서 흐름별로 독자적인 데이터를 어떻게 모으고 관리함?
// 벡터를 참조로 넘겨주기? 참조로 넘기면 다른 흐름에서 오염됨.
// 복사로 넘기기? 너무 많은 오버헤드.
// string을 넘기면 될듯
// 완성된 암호에서 한번에 문자를 체크할까
// 아니면 하나씩 넣을 때, 모음, 자음 수를 카운트하면서?
// 실시간 체크할 경우, 편하지만 숫자 관리가 어려움
// 그냥 string에서 자음, 모음 수를 리턴하는 함수를 만들고 마지막 때 검사하기

// 일단 string으로 했지만, int masking으로도 할 수 있을듯

bool Check(string password)
{
	int num_a = 0;
	int num_b = 0;

	for (char c : password)
	{
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		{
			num_a++;
		}
		else
		{
			num_b++;
		}
	}
	if (num_a > 0 && num_b > 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// int idx, string
void DFS(int idx, string password)
{
	if (password.size() == l)
	{
		if (Check(password))
		{
			cout << password << '\n';
		}
		return;
	}

	for (int i = idx; i < c; i++)
	{
		DFS(i + 1, password + collect[i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> l >> c;
	collect.reserve(c);
	for (int i = 0; i < c; i++)
	{
		char input;
		cin >> input;
		collect.push_back(input);
	}
	sort(collect.begin(), collect.end());

	string password;
	DFS(0, password);
}