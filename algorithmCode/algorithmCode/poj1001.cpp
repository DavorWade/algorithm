#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
POJ���ĺܺã��������Ҫ��һ������λ���ָ���˷������
Ҫ����������޴���λ���
����Ҫ�󣺴���������������� -- �ؼ��ǿ���������ˡ�
���Ա���������ر���Ҫ���ٴ�������Ҳ�����ĳЩ�����ġ�
����Գ���׳�ԵĿ��鵽���˱�̬�����ˡ�
ĳ�������Ĳ����������ݵ�ַ�� http://poj.org/showmessage?message_id=76017
������Щ���������µ��Ծ͹��ˡ�
�ҹؼ�©�˵�������
000.10  1
000000  1
000.00  1
.00000  0
000010  1
*/

/*
* remove '0' at the beginning/end of the number
@return: true:no decimal point
*/
bool standardizeDecimalPoint(string &s)
{
	while (!s.empty() && '0' == s[0]) s.erase(s.begin());
	if (s.empty()) s = "0";//��ֹn==1��ʱ��Ҫ���0

	bool noDot = true;
	for (unsigned i = 0; i < s.size() && noDot; i++)
	{
		if ('.' == s[i]) noDot = false;
	}
	if (noDot) return true;

	while (!s.empty() && '0' == s[s.size() - 1]) s.erase(s.end() - 1);
	if (!s.empty() && '.' == s[s.size() - 1]) s.erase(s.end() - 1);
	if (s.empty()) s = "0";
	return false;
}

/*
* return how much number there are in decimal part
*/
int handleDecimalPoint(string &s)
{
	if (standardizeDecimalPoint(s)) return 0;
	int fraction = 0;
	int j = 0;
	for (unsigned i = 0; i < s.size(); i++)
	{
		if (fraction > 0) fraction++;
		if (s[i] != '.') s[j++] = s[i];
		else fraction++;
	}
	s.erase(s.end() - 1);
	return fraction - 1;
}

string mulStr(string a, string b)
{
	if ("0" == a || "0" == b) return "0";
	int ap = handleDecimalPoint(a);
	int bp = handleDecimalPoint(b);

	string ans(a.size() + b.size(), '0');
	for (int i = a.size() - 1; i >= 0; i--)
	{
		int carry = 0;
		int an = a[i] - '0';
		for (int j = b.size() - 1; j >= 0; j--)
		{
			int bn = b[j] - '0';
			int sum = an * bn + carry + ans[i + j + 1] - '0';
			carry = sum / 10;
			ans[i + j + 1] = sum % 10 + '0';
		}
		if (carry) ans[i] += carry;
	}
	if (ap > 0 || bp > 0) ans.insert(ans.end() - ap - bp, '.');
	standardizeDecimalPoint(ans);
	return ans;
}

string sPow(string s, int n)
{
	if (s.empty() || "0" == s) return "0";//Ϊ�˳���Ľ�׳�ԣ�һ��Ҫ����
	if (0 == n) return "1";
	if (1 == n) return s;

	string divideStr = sPow(s, n / 2);

	divideStr = mulStr(divideStr, divideStr);
	if (n % 2) divideStr = mulStr(divideStr, s);
	return divideStr;
}

void Exponentiation()
{
	string s;
	int n;
	while (cin >> s >> n)
	{
		standardizeDecimalPoint(s);//��n==1��ʱ��
		cout << sPow(s, n) << endl;
	}
}

int main()
{
	Exponentiation();
	system("pause");
	return  0;
}