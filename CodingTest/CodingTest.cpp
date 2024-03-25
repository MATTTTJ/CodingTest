#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

#define prev HOON

using namespace std;

int n, o, A, B, asum, bsum;
string s, prev;

// �а� �ʸ� ����ؼ� ������ִ� �޼���
string print(int a)
{
	string d = "00" + to_string(a / 60);
	string e = "00" + to_string(a % 60);
	return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}

// ���ڸ� ��Ƽ���� ��ȯ���ִ� �޼���
int changeToInt(string a)
{
	// ���� ���� ������� ����
	return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

// �̱� ���� �ð��� �����ϴ� �޼���
void go(int &sum, string s)
{
	sum += (changeToInt(s) - changeToInt(prev));
}

int main()
{
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> o >> s;

		// ó���� �ȵ�
		if (A > B)
		{
			// ������ ������ �ð��� ���̸� ����
			go(asum, s);
		}
		else if (B > A)
		{
			go(bsum, s);
		}
		// ���� �̱�� �ֳ� üũ
		o == 1 ? A++ : B++;

		prev = s;
	}

	// ���� ����ϱ�
	if (A > B)
		go(asum, "48:00");
	else if (B > A)
		go(bsum, "48:00");

	cout << print(asum) << "\n";
	cout << print(bsum) << "\n";

	return 0;
}
