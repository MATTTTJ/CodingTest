#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

vector<pair<string, float>> var = { {"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0}, {"C+", 2.5}, {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0}, {"F", 0}, {"P", 0}};

vector<pair<string, float>> tmp;

string sub, s;
float n, sum;
float Allsum;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0; i < 20; i++)
	{
		cin >> sub >> n >> s;
		if(s != "P")
			sum += n;
		tmp.push_back({ s, n });
	}

	for(auto it : tmp)
	{
		// 패스는 통과
		if(it.first.find("P") != string::npos)
		{
			continue;
		}
		// 패스가 아닌 경우 학점과 전공 평균을 곱한 뒤, 학점을 전부 더한 값으로 나눈다. 
		else
		{
			float mul = 0;
			for(auto temp : var)
			{
				// 같은 글자 찾음
				if(mul == 0 && (temp.first.find(it.first) != string::npos))
				{
					mul = temp.second;
					break;
				}
			}
			Allsum += it.second * mul ;
		}
	}
	cout << Allsum / sum;

	return 0;
}



