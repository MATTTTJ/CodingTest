#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

string s;
// ���ӵǴ� ����, ���� ���� ī����
int lcnt, vcnt;

// �������� �Ǵ�
bool IsVowel(int idx)
{
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}


int main()
{
	while(true)
	{
		cin >> s;

		// end ������ �ߴ�
		// ����ó�� �ߴ� ��ʸ� �ִ� ���� �ǵ��� while�� Ȱ���غ���
		if (s == "end")
			break;

		lcnt = vcnt = 0;

		// Not acceptable �Ǵ�
		bool flag = 0;
		// ������ �����ϴ��� 
		bool is_include_v = 0;
		// ���� ���� �ε��� ���� ����
		int prev = -1;

		for(int i = 0; i < s.size(); i++)
		{
			int idx = s[i];
			// �����̸� ���� ī��Ʈ++, ���� ī��Ʈ ����, �����ϴ� ���� ī��Ʈ ���� 1
			if (IsVowel(idx))
			{
				lcnt++;
				vcnt = 0;
				is_include_v = 1;
			}
			else
			{
				vcnt++;
				lcnt = 0;
			}

			// �����̳� ������ 3�� ���޾� �ٴ� ���
			if (vcnt == 3 || lcnt == 3)
				flag = 1;

			// ���ڰ� 1���� �̻��̰�, ���� ���ڿ� ������, e �� o �� �ƴ� ��� 
			if( i >= 1 && (prev == idx) && (idx != 'e') && (idx != 'o'))
			{
				flag = 1;
			}
			// ���� ���� ����
			prev = idx;
		}
		// ������ �Ѱ��� ���ԵǾ����� ���� ���
		if (is_include_v == 0) flag = 1;

		if (flag)
			cout << "<" << s << ">" << " is not acceptable.\n";
		else
			cout << "<" << s << ">" << " is acceptable.\n";
	}

	return 0;
}
