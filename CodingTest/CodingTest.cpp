#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int n, m, cnt;
int a[1000001] = { 0,1 };
int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for(int i = 2; i <= m; i++)
	{
		for(int j = 2; i * j <= m; j++)
		{
			a[i * j] = 1; // 2���� �����ؼ� �ش� ���� ������ �ش� ���� ������� �����Ѵ�.
		}
	}

	for(int i = n; i <= m; i++)
	{
		if (!a[i])
			cout << i << "\n";
	}

	return 0;
}


