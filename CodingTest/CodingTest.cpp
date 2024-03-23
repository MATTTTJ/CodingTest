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
	// ��������
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
			// ���ڶ��
			if (s[j] < 65)
				ret += s[j];
			// ���ڰ� �ƴϸ鼭 ���� ������ ���� ���ڶ��
			else if (ret.size())
				go();
		}
		// ������ ���ڰ� ���ڿ��ٸ�
		if (ret.size())
			go();
	}

	// �������� ����
	sort(v.begin(), v.end(), cmp);

	for(string i : v)
	{
		cout << i << "\n";
	}
	return 0;
}
