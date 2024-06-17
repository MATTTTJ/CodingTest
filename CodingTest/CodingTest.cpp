#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

int n;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> m;
		sum += m;
		if (m > tmp)
		{
			tmp = m;
			dst = tmp * 0.01;
		}
	}

	ans = sum / dst;

	cout << ans / n;

	return 0;
}



