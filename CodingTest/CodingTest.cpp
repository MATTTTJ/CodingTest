#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>
#define MAX 51

using namespace std;


int n, maxCandy;
char candy[MAX][MAX];

void check()
{
	for(int i = 0; i < n; i++)
	{
		int count = 1;
		for(int j = 0; j < n; j++)
		{
			if(candy[i][j] == candy[i][j+1])
			{
				count++;
			}
			else
			{
				if (maxCandy < count)
					maxCandy = count;
				count = 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		int count = 1;
		for (int j = 0; j < n; j++)
		{
			if (candy[j][i] == candy[j+1][i])
			{
				count++;
			}
			else
			{
				if (maxCandy < count)
					maxCandy = count;
				count = 1;
			}
		}
	}
	
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> candy[i][j];
		}
	}

	// 행 단위로 교환해가며 가장 긴 부분을 체크함
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n-1; j++)
		{
			swap(candy[i][j], candy[i][j + 1]);
			check();
			swap(candy[i][j], candy[i][j + 1]);
		}
	}
	// 열 단위로 교환해가며 가장 긴 부분을 체크함
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			swap(candy[j][i], candy[j+1][i]);
			check();
			swap(candy[j][i], candy[j+1][i]);
		}
	}
	cout << maxCandy << '\n';

	return 0;
}


