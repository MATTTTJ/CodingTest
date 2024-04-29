#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

int E, S, M, e, s, m;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> E >> S >> M;

	E %= 15;
	S %= 28;
	M %= 19;

	// i를 제한할 순 없지만 보기에 나온 최대 값으로 제한 함
	for(int i = 1; i <= 7980; i++)
	{
		e = i % 15;
		s = i % 28;
		m = i % 19;
		// 입력된 값의 제한 값으로 나머지를 구한 뒤 모든 값들의 나머지 값이 동일해지는 지
		if(E == e && S == s && M == m)
		{
			cout << i;
			break;
		}
	}

	return 0;
}


