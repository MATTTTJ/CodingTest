#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

const int INF = 987654321;
char a[1004][1004];
int n, m, sx, sy, dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 }, ret, y, x;
int fire_check[1004][1004], person_check[1004][1004];

queue<pair<int, int>> q;

bool in(int a, int b)
{
	return 0 <= a && a < n && 0 <= b && b < m;
}

void Fire_Check()
{
	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!in(ny, nx))
				continue;
			// 불이 초기값이며, 벽인 경우
			if (fire_check[ny][nx] != INF || a[ny][nx] == '#')
				continue;
			// 불 가중치 + 1 
			fire_check[ny][nx] = fire_check[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

void Person_Check()
{
	// 방문 위치 가중치
	person_check[sy][sx] = 1;
	q.push({ sy, sx });
	while (q.size())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		// 가장자리에 있는 지 체크
		if (x == m - 1 || y == n - 1 || x == 0 || y == 0)
		{
			// 결과 가중치
			ret = person_check[y][x];
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!in(ny, nx))
				continue;
			if (person_check[ny][nx] || a[ny][nx] == '#')
				continue;
			//  불보다 먼저 이동했는지, 가중치를 비교한 뒤 먼저 이동한 것이 아니라면
			if (fire_check[ny][nx] <= person_check[y][x] + 1)
				continue;
			person_check[ny][nx] = person_check[y][x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main()
{
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	// 불을 인피니티 값으로 채워둔다.
	fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);
	for(int i =0 ; i < n; i++)
	{
		for(int j = 0; j< m; j++)
		{
			cin >> a[i][j];

			if (a[i][j] == 'F')
			{
				// 불은 여러 개 일 수 있다.
				fire_check[i][j] = 1;
				q.push({ i, j });
			}
			else if (a[i][j] == 'J')
			{
				// 지훈이 하나의 위치를 보관
				sy = i;  sx = j;
			}
		}
	}
	// 주어진 그래프에서 불의 가중치를 전부 계산한다.
	Fire_Check();
	// 주어진 그래프와 불의 가중치보다 이용해 탐색한다.
	Person_Check();

	if (ret != 0)
		cout << ret << "\n";
	else
		cout << "IMPOSSIBLE\n";

	return 0;
}


