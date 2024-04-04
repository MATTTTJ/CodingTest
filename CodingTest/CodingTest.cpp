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
	// 최댓값 갱신
	ret = max(ret, cnt);

	for(int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		 if(ny < 0 || ny >= R || nx < 0 || nx >= C)
			 continue;
		// 다음 방문할 글자를 인티저로 변환 후
		 int next = (int)(a[ny][nx] - 'A');
		 // 인티저 배열이 방문안한 0이라면
		if(visited[next] == 0)
		{
			// 해당 글자 배열의 값을 1로 변환 후
			visited[next] = 1;
			// 탐색한다. 탐색할 때 이미 방문됬던 글자 때문에 방문이 안된다면
			go(ny, nx, cnt + 1);
			// 되돌아와 0으로 바꾸고 다른 방향으로 탐색한다. 
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
	// 해당 문자열에 방문했는지 체크, 문자열 기반으로 잡았기 때문에 최대 배열 사이즈는 30으로 잡았음.
	visited[(int)a[0][0] - 'A'] = 1;
	// 출발위치, 최대 거리
	go(0, 0, 1);

	cout << ret << '\n';
	return 0;
}


