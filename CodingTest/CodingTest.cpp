#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int n, m;
string s;
map<string, int> mp;
map<int, string> mp2;
vector<string> str;
int main()
{
	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		cin >> s;
		mp[s] = i + 1;
		mp2[i + 1] = s;
	}

	for(int i = 0; i < m; i++)
	{
		cin >> s;
		str.push_back(s);
	}

	for(int i = 0; i < (int)str.size(); i++)
	{
		if (atoi(str[i].c_str()) == 0)
		{
			cout << mp[str[i]] << "\n";
		}
		else
			cout << mp2[atoi(str[i].c_str())] << "\n";
	}


	return 0;
}

