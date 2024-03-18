#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int n, ret;
string s;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		stack<char> stk;
		for(char a : s)
		{
			if (stk.size() && stk.top() == a)
				stk.pop();
			else
				stk.push(a);
		}

		if (stk.size() == 0)
			ret++;
	}

	cout << ret << endl;

	return 0;
}

