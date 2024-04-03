#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int n;
int a[1000004];
bool flag = false;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 2; i <= 1000000; i++)
	{
		a[i] = i;
	}
	for(int i = 2; i * i <= 1000000; i++)
	{
		if(a[i] == 0)
			continue;

		for(int j = i * i; j <= 1000000; j += i)
		{
			a[j] = 0;
		}
	}

	while (true)
	{
		cin >> n;
		if (n == 0)
			break;
		flag = false;
		for (int i = 1; i < n; i++)
		{
			if (a[i] == 0)
				continue;
			if (flag)
				break;

			for(int i = 3; i <= n; i += 2)
			{
				// �����佺�׳׽��� ü�� �̿��� n �� �ִ밪���� �Ҽ��� ���Ѵ�.
				// i�� 3���� ������ Ȧ���� ����� ���� 2�� Ű������, i�� n-i�� �Ҽ����� üũ�Ѵ�. i + n - i = n
				// ���� Ž������ ���� �ð� ���⵵�� �ʹ� Ŀ���ϱ� ���Ʈ������ ����
				if (a[i] != 0 && a[n - i] != 0)
				{
					cout << n << " = " << i << " + " << n - i << "\n";
					flag = true;
					break;
				}
			}
		}
		if (flag == false)
			cout << "Goldbach's conjecture is Wrong.\n";
	}
	return 0;
}


