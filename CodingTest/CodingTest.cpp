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

		// ���� �湮��ġ �̸� �湮 üũ
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
}

int solve()
{
	fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);

	for(pair<int, int> b : virusList)
	{
		// ù ���� ��ġ �湮 ����
		visited[b.first][b.second] = 1;

		dfs(b.first, b.second);
	}
	
	int cnt = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			// �湮���� �ʾҰ�, ���� �������� üũ
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
				// ���̷��� ��ġ���� �ʺ���Ž��
				virusList.push_back({ i,j });
			}
			if (a[i][j] == 0)
			{
				// 0�� ���� ����� 3�� �ɱ� ���� ����
				wallList.push_back({ i,j });
			}
		}
	}

	// 0�� ���� = ����� ���� �� �ִ� Ƚ��
	for (int i = 0; i < wallList.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			for(int k = 0; k < j; k++)
			{
				// 3���� ����� �ɾ ���� ������ �ִ� ���� ����
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
