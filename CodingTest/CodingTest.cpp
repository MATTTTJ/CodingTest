#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

int n, m;
bool isValid[10];

bool isMove(int num)
{
	if (num == 0)
	{
		if (isValid[0])
			return true;
		return false;
	}

	while(num)
	{
		// 넘어온 i 값의 몫이 망가진 버튼이라면 false
		// 버튼과 상관없이 한자리 수로 만든 뒤에 다시 망가진 버튼인지 체크
		if (!isValid[num % 10])
			return false;
		num /= 10;
	}

	return true;
}

// 시작 채널(100번)부터 n까지 +와 -로만 도달 가능한 횟수를 기본 값으로 지정
// +와 - 로만 n으로 이동 가능한 횟수 : abs(n-100)
// 0~500,000까지 사용 가능한 버튼으로 해당 채널로 이동이 가능한지 확인 
// 각 채널마다 N까지 + 또는 -로 이동하여 도달한 횟수를 계산한다.
// 위 방식들 중 최소값을 출력한다.

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	fill(isValid, isValid + 10, true);
	cin >> n >> m;

	if (n == 100)
	{
		cout << 0;
		return 0;
	}
	for(int i = 0; i < m; i++)
	{
		// 망가진 번호
		int idx;
		cin >> idx;
		isValid[idx] = false;
	}

	int result = abs(n - 100); // +,- 만 사용해서 n까지 채널 이동한 횟수

	for(int i = 0; i <= 1000000; i++)
	{
		if(isMove(i))
		{
			// i의 숫자 길이만큼 버튼 횟수 추가
			int move = to_string(i).length();
			move += abs(i - n);
			result = min(result, move);
		}
	}

	cout << result;

	return 0;
}


