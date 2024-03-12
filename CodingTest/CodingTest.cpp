#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Charge[3];
int a, b;
int cnt[104];
int ret;
int main()
{
	for (int i = 0; i < 3; i++)
		cin >> Charge[i];

	for( int i = 0; i < 3; i++)
	{
		cin >> a >> b;
		for (int j = a; j < b; j++)
			cnt[j]++;
	}
	for(int j = 1; j < 100; j++)
	{
		if(cnt[j])
		{
			if (cnt[j] == 1) ret += Charge[0];
			else if (cnt[j] == 2) ret += Charge[1] * 2;
			else ret += Charge[2] * 3;
		}
	}

	cout << ret << endl;

	return 0;
}

