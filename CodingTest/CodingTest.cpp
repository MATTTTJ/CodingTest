#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef unsigned long long ll;

int n,a;

int main()
{
	cin >> n;

	for(int i = 0; i <n; i++)
	{
		cin >> a;

		int ret2 { 0 }, ret5 { 0 };

		for(int j = 2;j <= a; j *= 2)
		{
			ret2 += a / j;
		}

		for(int j = 5; j <= a; j *= 5)
		{
			ret5 += a / j;
		}
		// 2와 5가 있어야 10이 만들어지니까 서로 조합이 되는 최소의 수가 0의 갯수다.
		cout << min(ret2, ret5) << endl;
	}
	
	return 0;
}
