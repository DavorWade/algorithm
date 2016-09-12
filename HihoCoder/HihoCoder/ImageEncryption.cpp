#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//http://hihocoder.com/contest/hiho114/problem/1

int n;
int A[100][100] = {};
int C[100][100] = {};
int B[100][100] = {};

void printA() {
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
}

bool isEqual(int bi, int bj, int sz) {
    for (int i = bi; i < bi + sz; ++i) {
        for (int j = bj; j < bj + sz; ++j) {
            if (A[i][j] != B[i][j])
                return false;
        }
    }
    return true;
}

void rotateA(int bi, int bj, int sz) {
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            C[bi + j][bj + sz - i - 1] = A[bi + i][bj + j];
        }
    }
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            A[bi + j][bj + sz - i - 1] = C[bi + j][bj + sz - i - 1];
        }
    }
}

bool isEncrypted(int bi, int bj, int sz) {
    for (int k = 0; k < 4; ++k) {
        rotateA(bi, bj, sz);
        if (isEqual(bi, bj, sz)) {
            return true;
        }

        if (sz % 2 == 0 && sz > 2) {
            int nsz = sz / 2;
            bool ret = true;
            for (int i = bi; i < bi + sz; i += nsz) {
                for (int j = bj; j < bj + sz; j += nsz) {
                    if (ret && !isEncrypted(i, j, nsz)) {
                        ret = false;
                    }
                }
            }
            if (ret) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int case_num;

    while (cin >> case_num) {
        while (case_num--) {
            cin >> n;
            for (int k = 0; k < 2; ++k) {
                for (int i = 0; i != n; ++i) {
                    for (int j = 0; j != n; ++j) {
                        if (k == 0) {
                            cin >> A[i][j];
                            C[i][j] = A[i][j];
                        }
                        else {
                            cin >> B[i][j];
                        }

                    }
                }
            }
            bool ret = isEncrypted(0, 0, n);
            if (ret)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    system("pause");
    return 0;
}
