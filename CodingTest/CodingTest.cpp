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
		// n�� m�� ���� ���� ���� ���
		puts("0");
		puts("1");
		return 0;
	}

	visited[n] = 1;
	cnt[n] = 1;
	// BFS�� q.push, !q.empty, int now = q.front(), q.pop()���̶� ����س���
	queue<int> q;
	q.push(n);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		// -1, +1, *2 �� �̵������ �ִ�.
		for(int next : {now -1, now +1, now*2})
		{
			// �����÷ο� üũ
			if( 0 <= next && next <= MAX)
			{
				// �湮 ���ߴٸ�
				if(!visited[next])
				{
					q.push(next);
					// ����ġ ����
					visited[next] = visited[now] + 1;
					// cnt[next] �� ó�� �湮�ϴ� ���̶�� 0�� ���̴�.
					// �������� �湮�ߴ� �������� ���� �湮�ϴ� ���� �������� ���Ѵ�.
					cnt[next] += cnt[now];
				}
				// �ٸ� �ִ� �Ÿ��� ��쿡�� �������� �߰��ϵ����Ѵ�.
				// �ִ� �Ÿ��� �ƴѵ� �ִܰŸ� �������� �߰��ϸ� �ȵ�.
				else if(visited[next] == visited[now] +1)
				{
					cnt[next] += cnt[now];
				}
			}
		}
	}
	// �ð��� �󸶳� �ɸ��� �� = �ִܰŸ� - 1
	cout << visited[m] - 1 << '\n';
	cout << cnt[m] << '\n';
		

	return 0;
}


