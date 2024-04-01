#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int dp[64][64][64], a[3], n, visited[64][64][64];
// ������ �� �ִ� ����� 6���� ��, BFS�� Ǯ����Ѵ�.
int _a[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 1, 9},
	{3, 9, 1},
	{1, 9, 3},
	{1, 3, 9}
};
// SVC�� ü�¿��� � �������� ������ �׷����� �׸������Ѵ�.
struct A
{
	int a, b, c;
};
queue<A> q;
// 0, 0, 0 �̵Ǵ� �ִܰŸ��� ã�´�.
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
		// ü���� 0�� �Ǵ� �κ�
		if (visited[0][0][0])
			break;
		for(int i =0; i < 6; i++)
		{
			// ������ �迭�� �ε����� �� ����.
			int na = max(0, a - _a[i][0]);
			int nb = max(0, b - _a[i][1]);
			int nc = max(0, c - _a[i][2]);
			if(visited[na][nb][nc])
				continue;
			// �ִܰŸ� �����
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


