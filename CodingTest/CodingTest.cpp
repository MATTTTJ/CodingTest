#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string S;
int a[26];

int main()
{
	cin >> S;

	for(auto c : S)
	{
		a[c - 'a']++;
	}

	for(int i = 0; i < 26; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}

