#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

string s;
int n, m;
string ans;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> m >> s;

		ans = "";
		for(char it : s)
		{
			for(int j = 0; j < m; j++)
			{
				ans += it;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}



