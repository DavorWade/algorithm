#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	* @param A: Array of integers.
	* return: The single number.
	*/
	int singleNumber(vector<int> &A) {
		// write your code here
		if (A.size() == 0) return 0;//�ύʱ���֣����Ϊ����Ҫ���ء�0��
		sort(A.begin(), A.end());
		for (int i = 0; i < A.size() - 1; i++) {
			if (A[i] == A[i + 1]) i++; //����󣬵���������������������Σ�������һ������ͬ��ֱ���ж����¸������ɣ�
			else return A[i];//�����ҵ���Ŀ����������
		}

		return A[A.size() - 1];
	}
};

