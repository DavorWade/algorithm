#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>

using namespace std;

void getNth(long long &n) {
    int m = 1;
    long long p = 10;
    long long offset_in_section;
    long long number;
    int offset_in_number;
    string num;

    if (n < 10) {
        printf("%lld\n", n);
        return;
    }

    while (p < n + 1) {
        m++;
        p += 9 * pow(10, m - 1) * m;
    }
    p -= 9 * pow(10, m - 1) * m;
    p = n - p;

    //cout << "p:" << p << endl;
    //cout << "m:" << m << endl;

    offset_in_section = p / m;
    number = pow(10, m - 1) + offset_in_section;
    offset_in_number = p % m;

    //cout << "offset_in_section:" << offset_in_section << endl;
    //cout << "number:" << number << endl;
    //cout << "offset_in_number:" << offset_in_number << endl;

    num = to_string(number);
    int rs = (int)(num[offset_in_number] - '0');
    printf("%d\n", rs);
}

/*
int main() {
    long long n;
    scanf("%lld", &n);
    //cout << "n:" << n << endl;

    getNth(n);

    system("pause");
    return 0;
}*/