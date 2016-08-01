#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

int 

int main() {
    vector<int> p;
    vector<int> q;
    int n;
    scanf("%d", &n);
    vector<vector<int> > t(n + 1, vector<int>());
    int min_money = 0;

    for (int i = 0; i < n; i++) {
        int pp, qq;
        scanf("%d %d", &pp, &qq);
        p.push_back(pp);
        q.push_back(qq);
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        t[a].push_back(b);
    }

    printf("%d\n", min_money);

    system("pause");
    return 0;
}