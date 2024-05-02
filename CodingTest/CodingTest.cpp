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
int tmp, dst, num;
int a[101];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0; i < 101; i++)
	{
		a[i] = i;
	}


	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		cin >> tmp >> dst;

		swap(a[tmp], a[dst]);
	}

	for(int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}



