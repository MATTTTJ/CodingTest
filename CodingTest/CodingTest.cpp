#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n;
vector<string> v;
string s, ret;

void go()
{
	while(true)
	{
		if (ret.size() && ret.front() == '0')
		{
			ret.erase(ret.begin());
		}
		else
			break;
	}
	if (ret.size() == 0) ret = "0";
	v.push_back(ret);
	ret = "";
}

bool cmp(string a, string b)
{
	// 오름차순
	if (a.size() == b.size())
		return a < b;

	return a.size() < b.size();
}

int main()
{
	cin >> n;

	for(int i = 0; i< n; i++)
	{
		cin >> s;
		ret = "";

		for(int j =0 ; j < s.size(); j++)
		{
			// 숫자라면
			if (s[j] < 65)
				ret += s[j];
			// 숫자가 아니면서 숫자 다음에 나온 글자라면
			else if (ret.size())
				go();
		}
		// 마지막 글자가 숫자였다면
		if (ret.size())
			go();
	}

	// 오름차순 정렬
	sort(v.begin(), v.end(), cmp);

	for(string i : v)
	{
		cout << i << "\n";
	}
	return 0;
}
