#include <stdlib.h>
#include <stdint.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
        const int m = A.size();
        const int n = B.size();
        int total = m + n;
        if (total & 0x1)
            return find_kth(A.begin(), A.end(), B.begin(), B.end(), total / 2 + 1);
        else
            return (find_kth(A.begin(), A.end(), B.begin(), B.end(), total / 2) 
                    + find_kth(A.begin(), A.end(), B.begin(), B.end(), total / 2 + 1)) / 2.0;
    }

private:
    typedef vector<int>::const_iterator Iter;
    static int find_kth(Iter beginA, Iter endA, Iter beginB, Iter endB, int k) {
        //always assume that m is equal or smaller than n
        const int m = distance(beginA, endA);
        const int n = distance(beginB, endB);
        if (m > n) return find_kth(beginB, endB, beginA, endA, k);
        if (m == 0) return *(beginB + k - 1);
        if (k == 1) return min(*beginA, *beginB);

        //divide k into two parts
        int ia = min(k / 2, m), ib = k - ia;
        if (*(beginA + ia - 1) < *(beginB + ib - 1))
            return find_kth(beginA + ia, endA, beginB, endB, k - ia);
        else if (*(beginA + ia - 1) > *(beginB + ib - 1))
            return find_kth(beginA, endA, beginB + ib, endB, k - ib);
        else
            return *(beginA + ia - 1);
    }
};