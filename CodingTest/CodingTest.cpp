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

	// i�� ������ �� ������ ���⿡ ���� �ִ� ������ ���� ��
	for(int i = 1; i <= 7980; i++)
	{
		e = i % 15;
		s = i % 28;
		m = i % 19;
		// �Էµ� ���� ���� ������ �������� ���� �� ��� ������ ������ ���� ���������� ��
		if(E == e && S == s && M == m)
		{
			cout << i;
			break;
		}
	}

	return 0;
}


