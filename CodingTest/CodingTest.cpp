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

int n, m, a[10][10], visited[10][10], ret;

vector<pair<int, int>> virusList, wallList;

void dfs(int y, int x)
{
	for(int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 1 || visited[ny][nx])
			continue;

		// 다음 방문위치 미리 방문 체크
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
}

int solve()
{
	fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);

	for(pair<int, int> b : virusList)
	{
		// 첫 시작 위치 방문 설정
		visited[b.first][b.second] = 1;

		dfs(b.first, b.second);
	}
	
	int cnt = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			// 방문하지 않았고, 안전 영역인지 체크
			if(a[i][j] == 0 && visited[i][j] == 0)
			{
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];

			if (a[i][j] == 2)
			{
				// 바이러스 위치에서 너비기반탐색
				virusList.push_back({ i,j });
			}
			if (a[i][j] == 0)
			{
				// 0인 곳에 기둥을 3개 심기 위해 보관
				wallList.push_back({ i,j });
			}
		}
	}

	// 0의 갯수 = 기둥을 꽂을 수 있는 횟수
	for (int i = 0; i < wallList.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			for(int k = 0; k < j; k++)
			{
				// 3개의 기둥을 심어서 안전 영역의 최대 값을 갱신
				a[wallList[i].first][wallList[i].second] = 1;
				a[wallList[j].first][wallList[j].second] = 1;
				a[wallList[k].first][wallList[k].second] = 1;
				ret = max(ret, solve());
				a[wallList[i].first][wallList[i].second] = 0;
				a[wallList[j].first][wallList[j].second] = 0;
				a[wallList[k].first][wallList[k].second] = 0;
			}
		}
	}

	cout << ret << "\n";

	return 0;
}
