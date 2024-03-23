#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

string s;
// 연속되는 자음, 모음 갯수 카운팅
int lcnt, vcnt;

// 모음인지 판단
bool IsVowel(int idx)
{
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}


int main()
{
	while(true)
	{
		cin >> s;

		// end 나오면 중단
		// 문제처럼 중단 사례를 주는 경우는 되도록 while을 활용해보자
		if (s == "end")
			break;

		lcnt = vcnt = 0;

		// Not acceptable 판단
		bool flag = 0;
		// 모음을 포함하는지 
		bool is_include_v = 0;
		// 이전 글자 인덱스 저장 변수
		int prev = -1;

		for(int i = 0; i < s.size(); i++)
		{
			int idx = s[i];
			// 모음이면 모음 카운트++, 자음 카운트 리셋, 포함하는 자음 카운트 갯수 1
			if (IsVowel(idx))
			{
				lcnt++;
				vcnt = 0;
				is_include_v = 1;
			}
			else
			{
				vcnt++;
				lcnt = 0;
			}

			// 자음이나 모음이 3개 연달아 붙는 경우
			if (vcnt == 3 || lcnt == 3)
				flag = 1;

			// 글자가 1글자 이상이고, 이전 글자와 같으며, e 나 o 가 아닌 경우 
			if( i >= 1 && (prev == idx) && (idx != 'e') && (idx != 'o'))
			{
				flag = 1;
			}
			// 이전 글자 저장
			prev = idx;
		}
		// 모음이 한개도 포함되어있지 않은 경우
		if (is_include_v == 0) flag = 1;

		if (flag)
			cout << "<" << s << ">" << " is not acceptable.\n";
		else
			cout << "<" << s << ">" << " is acceptable.\n";
	}

	return 0;
}
