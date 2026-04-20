#include <iostream>
#include <vector>
#include <string>

using namespace std;

char tree[26][3];

string preorder;
string inorder;
string postorder;

int FindIndex(char c)
{
	if (c == '.') return -1;
	for (int i = 0; i < 26; i++)
	{
		if (c == tree[i][0])
		{
			return i;
		}
	}
}

char Root(char c)
{
	int i = FindIndex(c);
	if (i == -1) return '.';
	return tree[i][0];
}

char Left(char c)
{
	int i = FindIndex(c);
	if (i == -1) return '.';
	return tree[i][1];
}

char Right(char c)
{
	int i = FindIndex(c);
	if (i == -1) return '.';
	return tree[i][2];
}

void Preorder(char c)
{
	if (c == '.') return;
	preorder.push_back(Root(c));
	Preorder(Left(c));
	Preorder(Right(c));
}

void Inorder(char c)
{
	if (c == '.') return;
	Inorder(Left(c));
	inorder.push_back(Root(c));
	Inorder(Right(c));
}

void Postorder(char c)
{
	if (c == '.') return;
	Postorder(Left(c));
	Postorder(Right(c));
	postorder.push_back(Root(c));
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> tree[i][j];
	}

	Preorder(tree[0][0]);
	Inorder(tree[0][0]);
	Postorder(tree[0][0]);
	cout << preorder << '\n';
	cout << inorder << '\n';
	cout << postorder << '\n';
}