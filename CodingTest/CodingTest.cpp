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
			// i를 약수로 가지는 수들에게 i를 더해줌
			g[i * j] += i;
		}
		g[i] += g[i - 1];
		// g(x)를 만들어주는 부분, 이 부분이 없으면 f[x]만 구하는 꼴이다.
	}

	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &c);

		printf("%lld\n", g[c]);
	}
	return 0;
}


