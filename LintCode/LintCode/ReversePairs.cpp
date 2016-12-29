#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
class Solution {
public:
    /**
    * @param A an array
    * @return total of reverse pairs
    */
    long long reversePairs(vector<int>& A) {
        // Write your code here

        return mergeSort(A, A.size());
    }

    int mergeSort(vector<int>& A, int array_size) {
        vector<int> temp(array_size, 0);
        return mergeSortVarity(A, temp, 0, array_size - 1);
    }

    int mergeSortVarity(vector<int>& A, vector<int>& temp, int left, int right) {
        int mid, inv_count = 0;
        if (right > left) {
            mid = left + (right - left) / 2;

            inv_count = mergeSortVarity(A, temp, left, mid);
            inv_count += mergeSortVarity(A, temp, mid + 1, right);

            inv_count += merge(A, temp, left, mid + 1, right);
        }
        return inv_count;
    }

    int merge(vector<int>& A, vector<int>& temp, int left, int mid, int right) {
        int i, j, k;
        int inv_count = 0;

        i = left;
        j = mid;
        k = left;
        while ((i <= mid - 1) && (j <= right)) {
            if (A[i] <= A[j]) {
                temp[k++] = A[i++];
            }
            else {
                temp[k++] = A[j++];

                inv_count = inv_count + (mid - i);
            }
        }

        while (i <= mid - 1)
            temp[k++] = A[i++];

        while (j <= right)
            temp[k++] = A[j++];

        for (i = left; i <= right; i++)
            A[i] = temp[i];

        return inv_count;
    }
};

class Solution {
public:
    /**
    * @param A an array
    * @return total of reverse pairs
    */
    long long reversePairs(vector<int>& A) {
        // Write your code here
        long long res = 0;
        vector<int> v;
        for (int i = A.size() - 1; i >= 0; --i) {
            int left = 0, right = v.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (A[i] > v[mid]) left = mid + 1;
                else right = mid;
            }
            v.insert(v.begin() + right, A[i]);
            res += right;
        }
        return res;
    }
};
