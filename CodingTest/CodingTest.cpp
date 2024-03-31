#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int n, m, ret, cnt;

int main()
{
	cin >> n ;

	for(int i =0; i< n; i++)
	{
		cin >> m;
		cnt = 0;
		for(int j = 1; j <= m ; j++)
		{
			if (m % j == 0)
				cnt++;
		}

		if (cnt == 2)
			ret++;
	}

	cout << ret << "\n";

	return 0;
}


