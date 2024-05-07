#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

string s, word;
int token, idx, cnt = 1;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, s);

	if ((s.length() == 1 && s[0] == ' ') || s.length() == 0) {
		cout << 0;
		return 0;
	}

	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == ' ')
		{
			cnt++;
		}
	}

	if (s[0] == ' ')
		cnt--;
	if(s[s.length() - 1] == ' ')
		cnt--;

	cout << cnt;
	return 0;
}



