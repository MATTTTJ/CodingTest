#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

int n;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		for(int j = n - i; j > 0; j--)
		{
			cout << " ";
		}

		for(int j = 2 *i -1; j > 0; j--)
		{
			cout << "*";
		}
		cout << endl;
	}

	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			cout << " ";
		}

		for(int j = 2 * (n-i) -1; j >0; j--)
		{
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}



