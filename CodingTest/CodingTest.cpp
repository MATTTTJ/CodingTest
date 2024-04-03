#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;
const int MAX = 200000;
int visited[MAX + 4];
long long cnt[MAX + 4];
int n, m;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	if(n==m)
	{
		// n과 m이 같은 값이 들어올 경우
		puts("0");
		puts("1");
		return 0;
	}

	visited[n] = 1;
	cnt[n] = 1;
	// BFS는 q.push, !q.empty, int now = q.front(), q.pop()만이라도 기억해내자
	queue<int> q;
	q.push(n);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		// -1, +1, *2 의 이동방식이 있다.
		for(int next : {now -1, now +1, now*2})
		{
			// 오버플로우 체크
			if( 0 <= next && next <= MAX)
			{
				// 방문 안했다면
				if(!visited[next])
				{
					q.push(next);
					// 가중치 증가
					visited[next] = visited[now] + 1;
					// cnt[next] 는 처음 방문하는 곳이라면 0일 것이다.
					// 이전까지 방문했던 가짓수를 다음 방문하는 곳의 가짓수에 더한다.
					cnt[next] += cnt[now];
				}
				// 다만 최단 거리일 경우에만 가짓수를 추가하도록한다.
				// 최단 거리가 아닌데 최단거리 가짓수를 추가하면 안됨.
				else if(visited[next] == visited[now] +1)
				{
					cnt[next] += cnt[now];
				}
			}
		}
	}
	// 시간이 얼마나 걸리는 지 = 최단거리 - 1
	cout << visited[m] - 1 << '\n';
	cout << cnt[m] << '\n';
		

	return 0;
}


