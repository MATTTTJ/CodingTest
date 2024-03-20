#include <iostream>
#pragma warning(disable:4996)
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

const int max_cnt = 51;
int m, n, k, y, x, ret, ny, nx, t;
int a[max_cnt][max_cnt];
bool visited[max_cnt][max_cnt];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void dfs(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;
		if (a[ny][nx] == 1 && !visited[ny][nx])
			dfs(ny, nx);
	}
}

int main()
{
	cin >> t;

	while (t--)
	{
		fill(&a[0][0], &a[0][0] + max_cnt * max_cnt, 0);
		fill(&visited[0][0], &visited[0][0] + max_cnt * max_cnt, 0);
		ret = 0;
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			a[y][x] = 1;
		}


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 1 && !visited[i][j])
				{
					dfs(i, j);
					ret++;
				}
			}
		}

		cout << ret << "\n";
	}
	return 0;
}
