#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 빈도정령 -> Custom Operator 생각나야함
// 1순위로 정렬 -> 많은 수 (카운팅)
// 2순위로 정렬 -> 먼저 나온 순위

typedef long long ll;
const ll INF = 1e18;
int n, c, a[1004];
vector<pair<int, int>> v;
map<int, int> mp, mp_first;

bool cmp(pair<int, int> a, pair<int,int> b)
{
	if(a.first == b.first)
	{
		return mp_first[a.second] < mp_first[b.second];
	}

	return a.first > b.first;
}

int main()
{
	cin >> n >> c;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]]++;
		if (mp_first[a[i]] == 0)
			mp_first[a[i]] = i + 1;
	}
	for(auto it : mp)
	{
		v.push_back({ it.second, it.first });
	}
	sort(v.begin(), v.end(), cmp);
	for(auto i : v)
	{
		for(int j =0; j < i.first; j++)
		{
			cout << i.second << " ";
		}
	}

	return 0;
}
