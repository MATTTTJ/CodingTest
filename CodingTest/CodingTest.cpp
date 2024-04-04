#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

const int max_n = 21;
const int dy[4] = { 1, 0, -1,0 };
const int dx[4] = { 0, 1, 0, -1 };

int R, C, visited[30], ret;
char a[max_n][max_n];

void go(int y, int x, int cnt)
{
	// �ִ� ����
	ret = max(ret, cnt);

	for(int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		 if(ny < 0 || ny >= R || nx < 0 || nx >= C)
			 continue;
		// ���� �湮�� ���ڸ� ��Ƽ���� ��ȯ ��
		 int next = (int)(a[ny][nx] - 'A');
		 // ��Ƽ�� �迭�� �湮���� 0�̶��
		if(visited[next] == 0)
		{
			// �ش� ���� �迭�� ���� 1�� ��ȯ ��
			visited[next] = 1;
			// Ž���Ѵ�. Ž���� �� �̹� �湮��� ���� ������ �湮�� �ȵȴٸ�
			go(ny, nx, cnt + 1);
			// �ǵ��ƿ� 0���� �ٲٰ� �ٸ� �������� Ž���Ѵ�. 
			visited[next] = 0;
		}
	}
	
	return;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			cin >> a[i][j];
		}
	}
	// �ش� ���ڿ��� �湮�ߴ��� üũ, ���ڿ� ������� ��ұ� ������ �ִ� �迭 ������� 30���� �����.
	visited[(int)a[0][0] - 'A'] = 1;
	// �����ġ, �ִ� �Ÿ�
	go(0, 0, 1);

	cout << ret << '\n';
	return 0;
}


