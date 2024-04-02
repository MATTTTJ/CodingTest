#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

vector<int> num;
vector<int> oper_str;
int n, ret = -987654321;
string s;

int oper(char a, int b, int c)
{
	if (a == '+') return b + c;
	if (a == '-') return b - c;
	if (a == '*') return b * c;
}

void go(int here, int _num)
{
	// 디버깅용
	//cout << _num << " : " << '\n';
	// 완전 탐색은 기저사례를 세워야한다. here가 끝이면
	if(here == num.size() -1)
	{
		// 맥스값은 최소값을 구해넣는다.
		ret = max(ret, _num);
		return;
	}
	// 핵심은 두 가지 경우의 수밖에 없다.
	go(here + 1, oper(oper_str[here],  _num, num[here + 1]));

	if(here + 2 <= num.size() - 1)
	{
		int temp = oper(oper_str[here + 1], num[here + 1], num[here + 2]);
		go(here + 2, oper(oper_str[here], _num, temp));
	}

	return;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> s;
	// 누적합을 그래프로 접근함
	// 인덱스를 기준으로 나눈다. 
	for(int i = 0; i < n; i++)
	{
		if(i % 2 == 0)
		{
			num.push_back(s[i] - '0');
		}
		else
		{
			oper_str.push_back(s[i]);
		}
	}
	// 초기값을 기반으로 탐색한다. 
	go(0, num[0]);
	cout << ret << "\n";

	return 0;
}


