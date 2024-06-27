#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

int n, m, a[4] = {25, 10, 5, 1}, b[4];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> m;
		//m *= 100;

		while(m > 0)
		{
			fill(&b[0], &b[4], 0);
			for(int j = 0; j < 4; j++)
			{
				if(m / a[j] > 0)
				{
					b[j] = m / a[j];

					m -= (b[j] * a[j]);
				}
			}
		}
		cout << b[0] << " " << b[1] << " " << b[2] << " " << b[3] << endl;
	}
	

	return 0;
}



