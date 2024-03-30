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
			// ������ �����̸鼭 �α� �̵��� �ʿ��� ������ �����̳ʿ� ��ǥ ����
			v.push_back({ ny, nx });
			// �� �α��� ���ϱ� 
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
					// ���� ������ �α��� ����
					sum = a[i][j];
					// ���� �켱 Ž��
					dfs(i, j, v);
					// ������ ������ ����
					if(v.size() == 1)
						continue;
					for(pair<int,int> b : v)
					{
						// ������ ������ �α��� �����ϰ� �й�
						a[b.first][b.second] = (int)(sum / v.size());
						flag = 1;
					}
				}
			}
		}
		// �α��̵��� �Ͼ�� �ʾ��� �� Ż��
		if (!flag)
			break;
		// �α��̵��� �Ͼ �� + 1;
		cnt++;
	}
	cout << cnt << "\n";

	
	return 0;
}


