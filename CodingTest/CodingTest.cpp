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

	// ġ�� üũ && �׵θ��� ����
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
		// ġ� ������ ���� �� ���� �ʱ�ȭ
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		// �׵θ� ġ�� ������ �ʱ�ȭ
		v.clear();
		// �׵θ� ġ��
		go(0, 0);
		// ġ�� � �ִ��� Ȯ��
		cnt2 = v.size();
		// ġ�� �׵θ� ������ ���� ��ȸ�ϸ� 0���� ���̱�
		for(pair<int,int> p : v)
		{
			a[p.first][p.second] = 0;
		}
		
		bool flag = 0;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				// ġ�� üũ
				if (a[i][j] != 0)
					flag = 1;
			}
		}
		// ��ð� �ɸ��� ��
		cnt++;
		// �� ������ �극��ũ
		if (!flag)
			break;
	}

	cout << cnt << '\n' << cnt2 << '\n';

	return 0;
}
