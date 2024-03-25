#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int n, a[1000004], ret[1000004];
stack<int> s;

int main()
{
	cin >> n;
	memset(ret, -1, sizeof(ret));

	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];

		// 오큰수가 발생되는 순간
		while(s.size() && a[s.top()] < a[i])
		{
			// 결과값을 담는다.
			ret[s.top()] = a[i];
			s.pop();
		}
		// 오큰수가 결정이 안됐으면 일단 담아놓는다. 
		s.push(i);
	}

	for (int i = 0; i < n; i++)
		cout << ret[i] << " ";

	return 0;
}
