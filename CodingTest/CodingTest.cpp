#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

#define y1 aa

char a[301][301];
int n, m, x1, y1, x2, y2;
typedef pair<int, int> pii;
int visited[301][301];
const int dy[4] = { -1, 0, 1 , 0 };
const int dx[4] = { 0, 1, 0, -1 };
int ret;
queue<int> q;

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
	y1--; x1--; y2--; x2--;
	for(int i = 0; i < n; i++)
	{
		scanf("%s", a[i]);
	}
	// 예를 들어 1,3 이면 1003이 나온다. 나누기, 모듈러 연산을 하면 1차원 배열로도 활용할 수 있음.
	q.push(1000 * y1 + x1);
	visited[y1][x1] = 1;
	int cnt = 0;
	
	while(a[y2][x2] != '0')
	{
		//  1만났을 때 cnt++
		cnt++;
		queue<int> temp;
		while(q.size())
		{
			// 2차원 변수를 하나의 인트로 표현하는 방법
			int y = q.front() / 1000;
			int x = q.front() % 1000;
			q.pop();

			for(int i = 0; i< 4; i ++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])
					continue;
				visited[ny][nx] = cnt;
				if (a[ny][nx] != '0')
				{
					a[ny][nx] = '0';
					// 0이 아닌 1을 만났을 때 temp에 보관
					temp.push(1000 * ny + nx);
				}
				else
					// 0일 땐 q 에 보관해 탐색함
					q.push(1000 * ny + nx);
			}
		}
		// 주난이가 1을 만났을 때 기존의 q는 지우고 temp로 대입한다.
		// 그럼 다시 while문에 1의 위치에서 새로 시작함
		q = temp;
	}

	printf("%d\n", visited[y2][x2]);

	return 0;
}


