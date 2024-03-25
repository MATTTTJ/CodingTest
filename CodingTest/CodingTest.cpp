#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <string>

using namespace std;

int main()
{
	string s;

	while(true)
	{
		getline(cin, s);

		if (s == ".") 
			break;

		stack<int> stk;
		
		bool check = true;

		for(int i = 0; i < s.length(); i++)
		{
			// 실패하는 조건을 우선
			if(s[i] == ')')
			{
				if(stk.size() == 0 || stk.top() == '[')
				{
					check = false;
					break;
				}
				else
				{
					stk.pop();
				}
			}
			// 실패하는 조건을 우선
			if(s[i] == ']')
			{
				if (stk.size() == 0 || stk.top() == '(')
				{
					check = false;
					break;
				}
				else
				{
					stk.pop();
				}
			}

			if (s[i] == '(')
				stk.push(s[i]);
			if (s[i] == '[')
				stk.push(s[i]);
		}
		// 실패하지 않고 스택이 비워진 상태라면
		if (check && stk.size() == 0)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}
