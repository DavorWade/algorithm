#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
	/**
	* @param A, B: Two integer arrays.
	* @return: Their smallest difference.
	*/
	int smallestDifference(vector<int> &A, vector<int> &B) {
		// write your code here
		int rs = INT_MAX;

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int i = 0;
		int j = 0;
		while (i < A.size() && j < B.size()) {
			rs = min(rs, abs(A[i] - B[j]));

			if (A[i] < B[j]) {
				i++;
			}
			else if (A[i] > B[j]) {
				j++;
			}
			else {
				rs = 0;
				break;
			}
		}

		return rs;
	}
};
