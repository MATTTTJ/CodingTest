#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int n;
long long sum;
int main()
{
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		sum += (n / i) * i;
	}
	cout << sum << "\n";
	return 0;
}


