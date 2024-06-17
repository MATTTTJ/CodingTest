#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

int a[26], cnt = 0;
string s;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	for(int i = 0; i < s.length(); i++)
	{
		if (s[i] < 97)
		{
			a[s[i] - 65]++;
		}
		else
			a[s[i] - 97]++;
	}

	int max = 0, max_idx = 0;

	for(int i = 0; i < 26; i++)
	{
		if(max < a[i])
		{
			max = a[i];
			max_idx = i;
		}
	}

	for(int i =0; i < 26; i++)
	{
		if (max == a[i])
			cnt++;
	}

	if (cnt > 1)
		cout << "?";
	else
		cout << (char)(max_idx + 65);

	return 0;
}



