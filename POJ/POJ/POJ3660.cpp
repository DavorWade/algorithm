#include <stdlib.h>
#include <stdio.h>
#include <vector>

#define MAXN 101

using namespace std;

//http://blog.csdn.net/nepaul/article/details/6416045

int graph[MAXN][MAXN];

void transitionClosure(int vertexNumber) {
    for (int k = 1; k <= vertexNumber; k++) {
        for (int i = 1; i <= vertexNumber; i++) {
            for (int j = 1; j <= vertexNumber; j++) {
                graph[i][j] = (graph[i][j] || (graph[i][k] && graph[k][j]));
            }
        }
    }
}

/*
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int a, b;

    // initialize graph matrix
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                graph[i][j] = 1;
                continue;
            }
            graph[i][j] = 0;
        }
    }

    // read data
    for (int i = 1; i <= M; i++) {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
    }

    transitionClosure(N);

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int tmp = 0;
        for (int j = 1; j <= N; j++) {
            if (graph[i][j] || graph[j][i]) tmp++;
        }

        if (tmp == N) ans++;
    }

    printf("%d\n", ans);

    system("pause");
    return 0;
}
*/