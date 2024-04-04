#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>

using namespace std;

int n, check[10];
char a[20];
vector<string> ret;

bool good(char x, char y, char op)
{
	// 숫자와 오퍼레이터가 맞는지 체크
	if (x < y && op == '<') 
		return true;
	if (x > y && op == '>')
		return true;

	return false;
}

void go(int idx, string num)
{
	if(idx == n + 1)
	{
		ret.push_back(num);

		return;
	}
	// 0~9까지의 수
	for(int i = 0; i <= 9; i++)
	{
		// 사용한 숫자라면
		if(check[i])
			continue;
		// 처음 사용하는 숫자라면 || 숫자와 오퍼가 합당한지 체크하는 함수를 통과한다면
		// i + '0' -> 숫자에 문자를 더해서 실제 숫자로 만든다. 문자로써 비교하게 만들어준다.
		if(idx == 0 || good(num[idx - 1], i + '0', a[idx - 1]))
		{
			check[i] = 1;
			go(idx + 1, num + to_string(i));
			// check[i] = 1인 상태에서 예를 들면 01인 상태에서 01 + 2~9 값을 못찾으면 다시 0 + 2~9 로 돌아가며 1은 check를 풀어준다.
			check[i] = 0;
		}
	}
	return;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	// 보통의 완탐과 같이 인덱스가 증가하는 형식의 함수
	go(0, "");
	// 완전탐색을 기반으로 만들어진 컨테이너를 정렬한다. 최댓값과 최소값을 뱉어냄
	sort(ret.begin(), ret.end());
	cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";

	return 0;
}


