#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string S, bS;

int main()
{
	cin >> S;
	bS = S;
	reverse(bS.begin(), bS.end());

	if (bS == S)
		cout << "1" << endl;
	else
		cout << "0" << endl;
	return 0;
}

