#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <string>

using namespace std;

int n, l, r;
string s;

bool check(string s)
{
	stack<char> stk;

	for(char c : s)
	{
		if (c == '(')
		{
			stk.push(c);
		}
		else
		{
			if (!stk.empty())
				stk.pop();
			else
				return false;
		}
	}
	// 전부 pop 되어야만 true 반환
	return stk.empty();
}

int main()
{
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> s;

		if (check(s))
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}
