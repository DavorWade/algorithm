#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

int N;

int solve(vector<int> v, int N) {
    long long rs = 0;

    while (N > 1) {
        int min1 = 0, min2 = 1;
        if (v[min1] > v[min2]) swap(min1, min2);
        for (int i = 2; i < N; i++) {
            if (v[i] < v[min1]) {
                min2 = min1;
                min1 = i;
            }
            else if (v[i] < v[min2]) {
                min2 = i;
            }
        }

        int sum = v[min1] + v[min2];
        rs += sum;

        if (min1 == N - 1) swap(min1, min2);
        v[min1] = sum;
        v[min2] = v[N - 1];
        N--;
    }

    return rs;
}

int main() {
    scanf("%d", &N);
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int tem;
        scanf("%d", &tem);
        v.push_back(tem);
    }

    int rs = solve(v, N);
    printf("%ll\n", rs);

    system("pause");
    return 0;
}