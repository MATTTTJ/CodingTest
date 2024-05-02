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
bool a[31];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	fill(&a[0], &a[0] + 31, false);
	for (int i = 0; i < 28; i++)
	{
		cin >> n;
		a[n-1] = true;
	}

	for(int i = 0; i < 30; i++)
	{
		if (!a[i])
			cout << i+1 << "\n";
	}


	return 0;
}



