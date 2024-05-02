#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

int n[9];
int cnt = -1, ans;
vector<int> v;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0; i < 9; i++)
	{
		cin >> n[i];
	}

	for (int i = 0; i < 9; i++)
	{
		if (n[i] > cnt)
		{
			cnt = n[i];
			ans = i;
		}
	}

	cout << cnt << "\n" << ans+1;

	return 0;
}



