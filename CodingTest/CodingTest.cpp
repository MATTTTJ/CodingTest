#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

long long int f[1000001] = { 0, };

long long int g[1000001] = { 0, };

int t, c;

int main()
{
	for(int i = 1; i <= 1000000; i++)
	{
		for(int j = 1; i * j <= 1000000; j++)
		{
			// i�� ����� ������ ���鿡�� i�� ������
			g[i * j] += i;
		}
		g[i] += g[i - 1];
		// g(x)�� ������ִ� �κ�, �� �κ��� ������ f[x]�� ���ϴ� ���̴�.
	}

	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &c);

		printf("%lld\n", g[c]);
	}
	return 0;
}


