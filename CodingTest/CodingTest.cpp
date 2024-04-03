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
				// 에라토스테네스의 체를 이용해 n 의 최대값까지 소수를 구한다.
				// i는 3부터 시작해 홀수를 만들기 위해 2씩 키워가며, i와 n-i가 소수인지 체크한다. i + n - i = n
				// 완전 탐색으로 돌면 시간 복잡도가 너무 커지니까 브루트포스로 접근
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


