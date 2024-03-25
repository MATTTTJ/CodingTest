#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

#define prev HOON

using namespace std;

int n, o, A, B, asum, bsum;
string s, prev;

// 분과 초를 계산해서 출력해주는 메서드
string print(int a)
{
	string d = "00" + to_string(a / 60);
	string e = "00" + to_string(a % 60);
	return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}

// 문자를 인티저로 변환해주는 메서드
int changeToInt(string a)
{
	// 작은 단위 기반으로 통일
	return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

// 이긴 팀에 시간을 적립하는 메서드
void go(int &sum, string s)
{
	sum += (changeToInt(s) - changeToInt(prev));
}

int main()
{
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> o >> s;

		// 처음엔 안들어감
		if (A > B)
		{
			// 이전에 득점된 시간과 차이를 적립
			go(asum, s);
		}
		else if (B > A)
		{
			go(bsum, s);
		}
		// 누가 이기고 있나 체크
		o == 1 ? A++ : B++;

		prev = s;
	}

	// 끝점 계산하기
	if (A > B)
		go(asum, "48:00");
	else if (B > A)
		go(bsum, "48:00");

	cout << print(asum) << "\n";
	cout << print(bsum) << "\n";

	return 0;
}
