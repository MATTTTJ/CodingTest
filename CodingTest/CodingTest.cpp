#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int n, m, cnt;
int num[15004];

int main()
{
	cin >> n;
	cin >> m;

	for(int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = i +1; j < n; j++)
		{
			if (num[i] + num[j] == m) cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}

