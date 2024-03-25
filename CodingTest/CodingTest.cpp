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

		// ��ū���� �߻��Ǵ� ����
		while(s.size() && a[s.top()] < a[i])
		{
			// ������� ��´�.
			ret[s.top()] = a[i];
			s.pop();
		}
		// ��ū���� ������ �ȵ����� �ϴ� ��Ƴ��´�. 
		s.push(i);
	}

	for (int i = 0; i < n; i++)
		cout << ret[i] << " ";

	return 0;
}
