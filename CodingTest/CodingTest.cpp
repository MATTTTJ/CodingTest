#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

string s, ss;
int n, m;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	for(char it : s)
	{
		if (it - 'A' <= 2)
			n += 3;
		else if (it - 'A' <= 5)
			n += 4;
		else if (it - 'A' <= 8)
			n += 5;
		else if (it - 'A' <= 11)
			n += 6;
		else if (it - 'A' <= 14)
			n += 7;
		else if (it - 'A' <= 18)
			n += 8;
		else if (it - 'A' <= 21)
			n += 9;
		else if (it - 'A' <= 25)
			n += 10;
	}

	cout << n;
	return 0;
}



