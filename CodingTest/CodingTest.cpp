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
int n, b;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> b;

	while(n != 0)
	{
		int tmp = n % b;
		if(tmp > 9)
		{
			// - 10 + 'A' 혹은 + 55
			tmp = tmp - 10 + 'A';
			b_num += tmp;
		}
		else
		{
			// 10 이하의 수
			b_num += ('0' + tmp);
		}
		n /= b;
	}
	reverse(b_num.begin(), b_num.end());

	cout << b_num << '\n';

	return 0;
}



