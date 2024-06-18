#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> vec_s = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
int idx;
string str;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;

	for(int i = 0; i < vec_s.size(); i++)
	{
		while(true)
		{
			idx = (int)str.find(vec_s[i]);
			if (idx == string::npos)
				break;
			str.replace(idx, vec_s[i].length(), "#");
		}
	}

	cout << str.length();

	return 0;
}



