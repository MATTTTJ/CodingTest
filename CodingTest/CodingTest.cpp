#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int a;
string name;
int cnt[154];
string ret;
int retcnt;
bool IsOK = false;
int main()
{
	cin >> a;

	for(int i = 0; i < a; i++)
	{
		cin >> name;

		cnt[name[0] - 'a']++;
	}

	for(auto a : cnt)
	{
		if (a >= 5)
		{
			ret += (retcnt + 'a');
			IsOK = true;
		}
		retcnt++;

	}

	if(IsOK == true)
	{
		cout << ret << endl;
	}
	else
	{
		cout << "PREDAJA" << endl;
	}


	return 0;
}

