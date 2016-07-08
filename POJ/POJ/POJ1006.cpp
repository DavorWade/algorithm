#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

//http://blog.csdn.net/u010885899/article/details/47253689

int main() {
	int a, b, c, d, j = 1;
	while (cin >> a >> b >> c >> d) {
		if (a + b + c + d == -4)
			break;

		cout << "Case " << j;
		j++;
		cout << ": the next triple peak occurs in ";
		int temp = (5544 * a + 14421 * b + 1288 * c - d + 21252) % 21252;
		if (temp == 0) {
			cout << 21252;
		}
		else
			cout << temp;
		cout << " days." << endl;
	}

	system("pause");
	return 0;
}
