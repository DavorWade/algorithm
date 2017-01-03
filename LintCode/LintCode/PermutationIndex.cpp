#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
    * @param A an integer array
    * @return a long integer
    */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        if (A.empty()) return 0;

        long long index = 1;
        long long factor = 1;
        for (int i = A.size() - 1; i >= 0; --i) {
            int rank = 0;
            for (int j = i + 1; j < A.size(); ++j) {
                if (A[i] > A[j]) ++rank;
            }
            index += rank * factor;
            factor *= (A.size() - i);
        }

        return index;
    }
};
