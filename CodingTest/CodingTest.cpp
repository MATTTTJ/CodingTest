#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int dp[64][64][64], a[3], n, visited[64][64][64];
// 공격할 수 있는 방법은 6가지 뿐, BFS로 풀어야한다.
int _a[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 1, 9},
	{3, 9, 1},
	{1, 9, 3},
	{1, 3, 9}
};
// SVC의 체력에서 어떤 데미지를 입을지 그래프를 그리고자한다.
struct A
{
	int a, b, c;
};
queue<A> q;
// 0, 0, 0 이되는 최단거리를 찾는다.
int solve(int a, int b, int c)
{
	visited[a][b][c] = 1;
	q.push({ a,b,c });
	while(q.size())
	{
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();
		// 체력이 0이 되는 부분
		if (visited[0][0][0])
			break;
		for(int i =0; i < 6; i++)
		{
			// 음수를 배열에 인덱싱할 수 없다.
			int na = max(0, a - _a[i][0]);
			int nb = max(0, b - _a[i][1]);
			int nc = max(0, c - _a[i][2]);
			if(visited[na][nb][nc])
				continue;
			// 최단거리 만들기
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({ na, nb,nc });
		}
	}
	return visited[0][0][0] - 1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << solve(a[0], a[1], a[2]) << "\n";

	return 0;
}


