#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

string b_num;
int n, sum;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> b_num >> n;

	for(int i = 0; i < (int)b_num.length(); i++)
	{
		// �ش� ����
		int tmp = b_num[(int)b_num.length() - (i + 1)];
		if ('0' <= tmp && tmp <= '9')
		{
			tmp = tmp - '0';
		}
		else
		{
			tmp = tmp + 10 - 'A';
		}
		// 10���� ��ȯ ���
		sum += (tmp * (int)pow(n, i));
	}
	cout << sum << '\n';

	return 0;
}



