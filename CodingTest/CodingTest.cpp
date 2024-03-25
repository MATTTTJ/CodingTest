#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int n;

int main()
{
	cin >> n;

	int i = 666;

	for(;; i++)
	{
		if(to_string(i).find("666") != string::npos)
		{
			n--;
		}
		if (n == 0)
			break;
	}

	cout << i << "\n";

	return 0;
}
