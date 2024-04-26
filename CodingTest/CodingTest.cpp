#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>

using namespace std;

int IsPrime[1000001] = {0, 1};

int n, m, cnt;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i <= 1000000; i++)
	{
		for (int j = 2; i * j <= 1000000; j++)
		{
			IsPrime[i * j] = 1;
		}
	}

	cin >> n >> m;

	for(int i = n; i <= m; i++)
	{
		if(!IsPrime[i])
		{
			cout << i << "\n";
		}
	}

	return 0;
}


