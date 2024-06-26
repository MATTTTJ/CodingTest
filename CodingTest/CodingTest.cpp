#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

const int MAX = 100;

int a[100][100] = { 0, };
int n, m, cnt, ans;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;

	for(int i = 0; i < cnt; i++)
	{
		cin >> n >> m;

		for(int i = n; i < n + 10; i++)
		{
			for (int j = m; j < m + 10; j++)
			{
				// 0에서 1로 체크하는 순간만 색종이의 넓이로 판단
				if (!a[i][j])
				{
					ans++;

					a[i][j] = 1;
				}
			}
		}
	}
	cout << ans;
	return 0;
}



