#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
 
int n, m, visited[54][54], mx;
char a[54][54];

void bfs(int y, int x)
{
	memset(visited, 0, sizeof(visited));
	visited[y][x] = 1;

	queue<pair<int, int>> q;
	q.push({ y,x });
	while(!q.empty())
	{
		tie(y, x) = q.front();
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if(visited[ny][nx])
				continue;
			 if(a[ny][nx] == 'W')
				 continue;
			// 가중치 쌓기
			 visited[ny][nx] = visited[y][x] + 1;
			 q.push({ ny, nx });
			 mx = max(mx, visited[ny][nx]);
		}
	}

	return;  
}


int main()
{
	cin >> n >> m;

	for(int i = 0; i< n; i++)
	{
		for(int j = 0; j < m ; j++)
		{
			cin >> a[i][j];
		}
	}


	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			// 특정 육지에서 다른 육지로 가는 최단거리 찾기 && 최대인 최단거리를 갱신하기
			if (a[i][j] == 'L')
				bfs(i, j);
		}
	}

	cout << mx - 1 << "\n";

	return 0;
}


