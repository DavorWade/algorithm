#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>

using namespace std;

void yanghui_triangle(const int n) {
	queue<int> q;
	/* Ԥ�ȷ����һ�е�1 */
	q.push(1);
	for (int i = 0; i <= n; i++) { /* ���д���*/
		int s = 0;
		q.push(s); /* �ڸ��м����һ��0*/
		/* �����i �е�i+2 ��ϵ��������һ��0��*/
		for (int j = 0; j < i + 2; j++) {
			int t;
			int tmp;
			t = q.front(); /* ��ȡһ��ϵ��������t*/
			q.pop();
			tmp = s + t; /* ������һ��ϵ������������*/
			q.push(tmp);
			s = t; /* ��ӡһ��ϵ������i+2 ����0*/
			if (j != i + 1) {
				printf("%d ", s);
			}
		}
		printf("\n");
	}
}

class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: A integer indicate the sum of max subarray
	*/
	int maxSubArray(vector<int> nums) {
		// write your code here
		int max_ending_here = nums[0];
		int max_so_far = nums[0];

		for (int i = 0; i < nums.size(); i++) {
			max_ending_here = max(max_ending_here + nums[i], nums[i]);
			max_so_far = max(max_so_far, max_ending_here);
		}

		return max_so_far;
	}
};


/*
int main(int argc, char *argv[]) {
	int rs = aplusb(2, 4);
	printf("%d", rs);

	printf("\n");
	system("pause");
	return 0;
}
*/
