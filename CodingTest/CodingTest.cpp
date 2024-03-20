#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

const int max_n = 101;
int n, ny, nx, d, ret = 1;
int a[max_n][max_n];
bool visited[max_n][max_n];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void dfs(int y, int x, int d)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;
		if (a[ny][nx] > d && !visited[ny][nx])
			dfs(ny, nx, d);
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}


	for (d = 1; d < 101; d++)
	{
		fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0);
		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] > d && !visited[i][j])
				{
					dfs(i, j, d);
					cnt++;
				}
			}
		}
		ret = max(ret, cnt);
	}

	cout << ret << endl;

	return 0;
}
