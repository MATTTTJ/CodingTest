#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

int n, m;
bool a[42];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	fill(&a[0], &a[0] + 42, false);
	for (int i = 0; i < 10; i++)
	{
		cin >> n;
		a[n % 42] = true;
	}

	for(int i = 0; i < 42; i++)
	{
		if (a[i])
			m++;
	}

	cout << m;

	return 0;
}



