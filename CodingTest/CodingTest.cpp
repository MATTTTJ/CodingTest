#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;
#define prev aaa
#define next aaaa

const int max_n = 200004;
int visited[max_n], prev[max_n], n, k, ret, here, cnt, next;
vector<int> v;
queue<int> q;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	visited[n] = 1;
	q.push(n);
	while(!q.empty())
	{
		here = q.front();
		q.pop();
		if (here == k)
		{
			ret = visited[k];
			break;
		}
		for (int next : {here - 1, here + 1, here * 2})
		{
			if (next >= max_n || next < 0 || visited[next])
				continue;
			visited[next] = visited[here] + 1;
			prev[next] = here;
			q.push(next);
		}
	}
	// prev �迭 �ȿ� ���� ������ ���� �������
	for(int i = k ; i != n; i = prev[i])
	{
		v.push_back(i);
	}

	v.push_back(n);
	// �ִܰŸ� -1�� �ּ� �ð��̴�. 
	cout << ret - 1 << '\n';
	// �湮�ߴ� �� ������
	reverse(v.begin(), v.end());

	for (int i : v)
		cout << i << ' ';
	return 0;
}


