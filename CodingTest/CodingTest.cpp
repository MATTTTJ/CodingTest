#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

int n, m,l;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> l;

	if(n == m || m == l || n == l)
	{
		if (n == m && m == l && n == l)
		{
			cout << 10000 + 1000 * n;
		}
		else if(m == l)
			cout << 1000 + m * 100;
		else
			cout << 1000 + n * 100;
	}
	else
	{
		int big = -123456789;
		big = max(n, big);
		big = max(m, big);
		big = max(l, big);
		cout << big * 100;
	}

	return 0;
}



