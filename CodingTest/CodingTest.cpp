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
		// �Ѿ�� i ���� ���� ������ ��ư�̶�� false
		// ��ư�� ������� ���ڸ� ���� ���� �ڿ� �ٽ� ������ ��ư���� üũ
		if (!isValid[num % 10])
			return false;
		num /= 10;
	}

	return true;
}

// ���� ä��(100��)���� n���� +�� -�θ� ���� ������ Ƚ���� �⺻ ������ ����
// +�� - �θ� n���� �̵� ������ Ƚ�� : abs(n-100)
// 0~500,000���� ��� ������ ��ư���� �ش� ä�η� �̵��� �������� Ȯ�� 
// �� ä�θ��� N���� + �Ǵ� -�� �̵��Ͽ� ������ Ƚ���� ����Ѵ�.
// �� ��ĵ� �� �ּҰ��� ����Ѵ�.

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
		// ������ ��ȣ
		int idx;
		cin >> idx;
		isValid[idx] = false;
	}

	int result = abs(n - 100); // +,- �� ����ؼ� n���� ä�� �̵��� Ƚ��

	for(int i = 0; i <= 1000000; i++)
	{
		if(isMove(i))
		{
			// i�� ���� ���̸�ŭ ��ư Ƚ�� �߰�
			int move = to_string(i).length();
			move += abs(i - n);
			result = min(result, move);
		}
	}

	cout << result;

	return 0;
}


