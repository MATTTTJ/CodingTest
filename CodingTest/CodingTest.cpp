#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, l, r, sum, cnt;
int a[54][54], visited[54][54];
vector<pair<int, int>> v;

void dfs(int y, int x, vector<pair<int,int>>& v)
{
	for(int i = 0; i< 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || nx < 0 || ny >=n || nx >= n || visited[ny][nx])
			continue;
		if(abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r)
		{
			visited[ny][nx] = 1;
			// 인접한 국가이면서 인구 이동이 필요한 국가는 컨테이너에 좌표 보관
			v.push_back({ ny, nx });
			// 총 인구수 더하기 
			sum += a[ny][nx];
			dfs(ny, nx, v);
		}
	}
}

int main()
{
	cin >> n >> l >> r;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	while(true)
	{
		bool flag = 0;
		fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(!visited[i][j])
				{
					v.clear();
					visited[i][j] = 1;
					v.push_back({ i,j });
					// 현재 국가의 인구수 대입
					sum = a[i][j];
					// 깊이 우선 탐색
					dfs(i, j, v);
					// 인접한 국가가 없음
					if(v.size() == 1)
						continue;
					for(pair<int,int> b : v)
					{
						// 인접한 국가에 인구수 동등하게 분배
						a[b.first][b.second] = (int)(sum / v.size());
						flag = 1;
					}
				}
			}
		}
		// 인구이동이 일어나지 않았을 때 탈출
		if (!flag)
			break;
		// 인구이동이 일어난 날 + 1;
		cnt++;
	}
	cout << cnt << "\n";

	
	return 0;
}


