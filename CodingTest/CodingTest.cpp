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
int a[26], cnt;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	fill(&a[0], &a[0] + 26, -1);

	cin >> s;

	for(auto it : s)
	{
		if(a[(int)it - 'a'] != -1)
		{
			cnt++;
			continue;
		}

		a[(int)it - 'a'] = cnt;
		cnt++;
	}

	for(int i = 0; i < 26; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}



