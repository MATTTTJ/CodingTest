#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n,a;
vector<int> tmp;
int main()
{
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> a;

		int ret2 = 0, ret5 = 0 ;

		for(int j = 2; j <= a; j *= 2)
		{
			ret2 += a / j;
		}

		for(int j = 5; j <= a; j *= 5)
		{
			ret5 += a / j;
		}
		tmp.push_back(min(ret2, ret5));
	}

	for (auto it : tmp)
		cout << it << "\n";

	return 0;
}
