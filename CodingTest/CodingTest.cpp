#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int h, w, cnt;
char a[104][104], ret[104][104];
bool flag = false;

string s;
vector<string> tmp;

int main()
{
	cin >> h >> w;

	for(int i = 0; i < h; i++)
	{
		cin >> s;
		tmp.push_back(s);
	}

	for (int i = 0; i < h; i++)
	{
		flag = false;
		cnt = 0;
		
		for (int j = 0; j < w; j++)
		{
			if(flag == false && tmp[i][j] == '.')
			{
				ret[i][j] = -1;
			}
			else if(tmp[i][j] == 'c')
			{
				ret[i][j] = 0;
				flag = true;
				cnt = 0;
			}
			else if(flag == true && tmp[i][j] == '.')
			{
				cnt++;
				ret[i][j] += cnt;
			}
		}
	}

	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			int b = ret[i][j];
			cout << b << " ";

			if (j + 1 == w)
				cout << endl;
		}
	}

	return 0;
}
