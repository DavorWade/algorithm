//2016-9-26

#include <stdlib.h>
#include <stdio.h>

#define N 2000

using namespace std;

char cows[N + 1];

void solve(char *cows, int n) {
    int a = 0, b = n - 1;
    int count = 0;

    while (a <= b) {
        bool left = false;

        for (int i = 0; a + i <= b; i++) {
            if (cows[a + i] < cows[b - i]) {
                left = true;
                break;
            }
            else if (cows[a + i] > cows[b - i]) {
                left = false;
                break;
            }
        }
       
        if (left) putchar(cows[a++]);
        else putchar(cows[b--]);

        count++;
        if (count == 80) {
            putchar('\n');
            count = 0;
        }
    }

    putchar('\n');
}

/*
int main() {
    int n;
    scanf("%d", &n);
    getchar(); //get the '\n'

    for (int i = 0; i < n; i++) {
        //cows[i] = getchar();
        scanf("%c", &cows[i]);
        getchar();
    }

    solve(cows, n);

    system("pause");
    return 0;
}
*/