#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param A an integer array
    * @return void
    */
    void sortIntegers2(vector<int>& A) {
        // Write your code here
        if (A.size() < 1) return;

        // note that right = A.size() - 1
        // quickSort(A, 0, A.size()-1);

        mergeSort(A, 0, A.size() - 1);
    }

    void quickSort(vector<int>& A, int left, int right) {
        int l = left;
        int r = right;
        int pivot = l + (r - l) / 2;
        int pivotVal = A[pivot];

        while (l <= r) {
            while (A[l] < pivotVal) l++;
            while (pivotVal < A[r]) r--;

            if (l <= r) {
                int tem = A[l];
                A[l] = A[r];
                A[r] = tem;

                l++;
                r--;
            }
        }

        if (left < r) quickSort(A, left, r);
        if (l < right) quickSort(A, l, right);
    }

    void mergeSort(vector<int>& A, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(A, left, mid);
            mergeSort(A, mid + 1, right);

            merge(A, left, mid, right);
        }
    }

    void merge(vector<int>& A, int left, int mid, int right) {
        vector<int> l;
        vector<int> r;
        for (int i = left; i <= mid; i++) l.push_back(A[i]);
        for (int j = mid + 1; j <= right; j++) r.push_back(A[j]);

        int i = 0;
        int j = 0;
        int k = left; // k = left, not k = 0
        while (i < l.size() && j < r.size()) {
            if (l[i] <= r[j]) {
                A[k] = l[i++];
            }
            else if (l[i] > r[j]) {
                A[k] = r[j++];
            }
            k++;
        }

        while (i < l.size()) {
            A[k++] = l[i++];
        }

        while (j < r.size()) {
            A[k++] = r[j++];
        }
    }
};
