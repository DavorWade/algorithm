#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cstdio>
#include <queue>
#include <functional> // std::greater

using namespace std;

typedef long long int lli;

//https://programming-study-notes.blogspot.com/2014/03/poj-3253-fence-repair.html

int main() {
    lli N, L;
    while (scanf("%lld", &N) != EOF) {
        priority_queue<lli, vector<lli>, greater<lli> > PQ;

        for (lli i = 0; i < N; ++i) {
            scanf("%lld", &L);
            PQ.push(L);
        }

        lli sum = 0;
        while (PQ.size() > 1) {
            lli tmp = PQ.top();
            PQ.pop();
            tmp += PQ.top();
            PQ.pop();

            sum += tmp;
            PQ.push(tmp);
        }
        printf("%lld\n", sum);
    }

    system("pause");
    return 0;
}
