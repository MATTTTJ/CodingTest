#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

const int max_n = 1501;
const int dy[4] = { 1, 0, -1, 0 };
const int dx[4] = { 0, 1, 0, -1 };
int visited_swan[max_n][max_n], visited[max_n][max_n], R, C, day, swanY, swanX, y, x;
char a[max_n][max_n];
queue<pair<int, int>> waterQ, water_tempQ, swanQ, swan_tempQ;
string s;

void Qclear(queue<pair<int,int>> &q)
{
	queue<pair<int, int>> empty;
	swap(q, empty);
}

void water_melting()
{
	while(waterQ.size())
	{
		// 처음 모든 물의 위치에서 만난 빙판 X 값을 보관해둘 수 있음.
		// 그 다음 모아둔 모든 첫번째 빙판들 위치에서 그 다음 빙판을 보관하도록 함
		tie(y, x) = waterQ.front();
		waterQ.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx])
				continue;
			// 다음 이동 위치가 얼음이라면 물로 변경하고 물로 변경한 위치를 tempQ 에 보관한다.
			// 그래야 다음날 물로 바꿀 얼음의 위치를 알 수 있기 때문
			if(a[ny][nx] == 'X')
			{
				visited[ny][nx] = 1;
				water_tempQ.push({ ny, nx });
				a[ny][nx] = '.';
			}
		}
	}
}

bool move_swan()
{
	// 현재 백조가 있다면
	while(swanQ.size())
	{
		// 현재 위치 받기
		tie(y, x) = swanQ.front();
		swanQ.pop();

		for(int i = 0; i < 4; i ++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited_swan[ny][nx])
				continue;
			// 백조가 방문한 위치 체크
			visited_swan[ny][nx] = 1;
			// 물이라면 계속해서 이동해야 하기 때문에 swanQ에 푸쉬
			if (a[ny][nx] == '.')
				swanQ.push({ ny,nx });
			// 얼음이라면 멈춰야하기 때문에 현재 위치를 보관해둘 tempQ에 푸쉬
			else if (a[ny][nx] == 'X')
				swan_tempQ.push({ ny,nx });
			// 다른 백조를 만났다면 true
			else if (a[ny][nx] == 'L')
				return true;
		}
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for(int i = 0; i < R; i++)
	{
		cin >> s;
		for(int j = 0; j < C; j++)
		{
			a[i][j] = s[j];
			// 백조의 위치 보관
			if(a[i][j] == 'L')
			{
				swanY = i;
				swanX = j;
			}
			// 물의 위치를 Q에 보관, 백조의 위치 또한 물이다.
			if(a[i][j] == '.' || a[i][j] == 'L')
			{
				// visited 배열은 얼음을 물로 녹이기 위한 배열이기 때문에 이미 물인 위치는 방문처리를 하도록 한다.
				visited[i][j] = 1;
				// 물 큐에 보관
				waterQ.push({ i,j });
			}
		}
	}
	// 백조의 현재 위치를 스완Q에 보관
	swanQ.push({ swanY, swanX });
	// 백조 방문체크
	visited_swan[swanY][swanX] = 1;
	while(true)
	{
		// 백조가 움직인다. 다른 백조를 만나면 브레이크
		if (move_swan())
			break;
		// 물이 녹는다.
		water_melting();
		// 녹아서 tempQ에 추가된 물을 현재 물을 보관중인 waterQ에 대입
		waterQ = water_tempQ;
		// 새롭게 이동한 백조의 위치를 swanQ에 대입
		swanQ = swan_tempQ;
		// 사용했던 tempQ는 초기화
		Qclear(water_tempQ);
		Qclear(swan_tempQ);
		// 날짜 추가
		day++;
	}

	cout << day << "\n";

	return 0;
}


