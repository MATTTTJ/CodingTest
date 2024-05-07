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

	cin >> s >> ss;

	swap(s[0], s[2]);
	swap(ss[0], ss[2]);

	if (stoi(s) > stoi(ss))
	{
		cout << s;
	}
	else
		cout << ss;

	return 0;
}



