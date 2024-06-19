#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

int a[9][9], max_idx = -123, n, m;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			cin >> a[i][j];
			if (max_idx < a[i][j])
			{
				max_idx = a[i][j];
				n = i+1; m = j+1;
			}
		}
	}
	cout << max_idx << endl;
	cout << n << " " << m;

	return 0;
}



