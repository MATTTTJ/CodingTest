#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int a;
string origin,tmp;
vector<string> ret;

int main()
{
	cin >> a;
	cin >> origin;

	string pre, suf;

	int pos = origin.find('*');

	pre = origin.substr(0, pos);
	suf = origin.substr(pos + 1);

	for(int i = 0; i < a; i++)
	{
		cin >> tmp;

		if (pre.size() + suf.size() > tmp.size())
		{
			//cout << "NE" << endl;
			ret.push_back("NE");
		}
		else
		{
			if (pre == tmp.substr(0, pre.size()) && suf == tmp.substr(tmp.size() - suf.size()))
				//cout << "DA" << endl;
			ret.push_back("DA");
			else
				//cout << "NE" << endl;
				ret.push_back("NE");
		}
	}

	for(auto x : ret)
	{
		cout << x << endl;
	}

	return 0;
}

