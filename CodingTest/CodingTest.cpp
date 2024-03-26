#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <string>
#include <cstring>

using namespace std;
int n, m, a[51][51], visited[51][51], result = 987654321;

vector<pair<int,int>> house;
vector<pair<int, int>> chicken;
vector<vector<int>> chickenList;



void combi(int start, vector<int> v)
{
	if(v.size() == m)
	{
		chickenList.push_back(v);
		return;
	}

	for(int i = start + 1; i < chicken.size(); i++)
	{
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	return;
}


int main()
{
	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];

			if (a[i][j] == 1)
			{
				house.push_back({ i, j });
			}
			if (a[i][j] == 2)
			{
				chicken.push_back({ i,j });
			}
		}
	}

	vector<int> v;
	combi(-1, v);
	for(vector<int> cList : chickenList)
	{
		int ret = 0;
		for(pair<int, int> home : house)
		{
			int _min = 987654321;
			for(int ch : cList)
			{
				int _dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);

				_min = min(_min, _dist);
			}
			ret += _min;
		}
		result = min(result, ret);
	}
	cout << result << "\n";

	return 0;
}


