#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include <algorithm>

using namespace std;

/*
int main() {
    int N, M;
    string composition;
    vector<string> illegalPairs;

    scanf("%d", &N);
    cin >> composition;
    scanf("%d", &M);
    vector<int> dp(N + 1, INT_MAX);

    for (int i = 0; i < M; i++) {
        string tem;
        cin >> tem;
        illegalPairs.push_back(tem);

        string temp;
        temp.assign(tem.rbegin(), tem.rend());
        illegalPairs.push_back(temp);
    }

    for (int j = 1; j < composition.size(); j++) {
        string lastTwoChars = composition.substr(j - 1, 2);
        if (find(illegalPairs.begin(), illegalPairs.end(), lastTwoChars) == illegalPairs.end()) {
            dp[j + 1] = dp[j];
        }
        else {
            dp[j + 1] = min(dp[j], dp[j - 1] + 1);
        }
    }

    printf("%d\n", dp[N]);
    return 0;
}
*/