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
	// ���ڿ� ���۷����Ͱ� �´��� üũ
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
	// 0~9������ ��
	for(int i = 0; i <= 9; i++)
	{
		// ����� ���ڶ��
		if(check[i])
			continue;
		// ó�� ����ϴ� ���ڶ�� || ���ڿ� ���۰� �մ����� üũ�ϴ� �Լ��� ����Ѵٸ�
		// i + '0' -> ���ڿ� ���ڸ� ���ؼ� ���� ���ڷ� �����. ���ڷν� ���ϰ� ������ش�.
		if(idx == 0 || good(num[idx - 1], i + '0', a[idx - 1]))
		{
			check[i] = 1;
			go(idx + 1, num + to_string(i));
			// check[i] = 1�� ���¿��� ���� ��� 01�� ���¿��� 01 + 2~9 ���� ��ã���� �ٽ� 0 + 2~9 �� ���ư��� 1�� check�� Ǯ���ش�.
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
	// ������ ��Ž�� ���� �ε����� �����ϴ� ������ �Լ�
	go(0, "");
	// ����Ž���� ������� ������� �����̳ʸ� �����Ѵ�. �ִ񰪰� �ּҰ��� ��
	sort(ret.begin(), ret.end());
	cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";

	return 0;
}


