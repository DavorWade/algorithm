#include<iostream>
#include<string>

using namespace std;

string m[19] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet" };
string d[20] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };

int summons(string hm) {
	for (int i = 0; i<19; i++) {
		if (hm == m[i]) {
			return i;
		}
	}
	return -1;
}

/*
int main() {
	long n, i, j, k;
	cin >> n;
	cout << n << endl;
	for (i = 0; i<n; i++) {
		long hd;
		string hm;
		long hy;
		cin >> hd >> hm >> hm >> hy;
		long hm1 = summons(hm);
		long hdays = 0;
		hdays = hy * 365 + 20 * hm1 + hd;

		long y = hdays / 260;
		long  days = hdays % 260;

		cout << days % 13 + 1 << " " << d[days % 20] << " " << y << endl;
	}

	system("pause");
	return 0;
}
*/