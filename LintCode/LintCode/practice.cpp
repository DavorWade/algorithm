#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

void change(int n, const int d) {
	stack<int> s;
	int tem;

	while (n != 0) {
		tem = n % d;
		n = n / d;
		s.push(tem);
	}

	while (!s.empty()) {
		tem = s.top();
		s.pop();
		printf("%d", tem);
	}
}


int main(int argc, char *argv[]) {
	change(7, 4);
	printf("\n");

	system("pause");
	return 0;
}
