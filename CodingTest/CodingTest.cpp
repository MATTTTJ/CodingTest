#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

int n, m;
int tmp, dst;
int a[101];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i < n + 1; i++)
	{
		a[i] = i;

	}
	for (int i = 1; i <= m; i++)
	{
		cin >> tmp >> dst;

		if (tmp != dst)
		{
			for (int j = 0; j <= (dst - tmp) / 2; j++)
			{
				swap(a[tmp + j], a[dst - j]);
			}
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}



