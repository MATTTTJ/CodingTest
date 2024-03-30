#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int n, m, ret1, ret2;

int gcd(int a, int b)
{
	int c = a % b;
	while(c != 0)
	{
		a = b;
		b = c;
		c = a % b;
	}

	return b;
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int main()
{
	cin >> n >> m;

	cout << gcd(n, m) << "\n" << lcm(n, m);
	return 0;
}


