#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <string>

using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

int a[104][104], visited[104][104];
int n, m, cnt, cnt2;
vector<pair<int, int>> v;

void go(int y, int x)
{
	visited[y][x] = 1;

	// 치즈 체크 && 테두리만 보관
	if (a[y][x] == 1)
	{
		v.push_back({ y, x });
		return;
	}

	for(int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx])
			continue;

		go(ny, nx);
	}
}

int main()
{
	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	while(true)
	{
		// 치즈가 완전히 녹을 때 까지 초기화
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		// 테두리 치즈 보관용 초기화
		v.clear();
		// 테두리 치즈
		go(0, 0);
		// 치즈 몇개 있는지 확인
		cnt2 = v.size();
		// 치즈 테두리 보관한 벡터 순회하며 0으로 녹이기
		for(pair<int,int> p : v)
		{
			a[p.first][p.second] = 0;
		}
		
		bool flag = 0;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				// 치즈 체크
				if (a[i][j] != 0)
					flag = 1;
			}
		}
		// 몇시간 걸리는 지
		cnt++;
		// 다 녹으면 브레이크
		if (!flag)
			break;
	}

	cout << cnt << '\n' << cnt2 << '\n';

	return 0;
}
