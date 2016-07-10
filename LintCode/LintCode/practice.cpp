#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>

using namespace std;

void yanghui_triangle(const int n) {
	queue<int> q;
	/* 预先放入第一行的1 */
	q.push(1);
	for (int i = 0; i <= n; i++) { /* 逐行处理*/
		int s = 0;
		q.push(s); /* 在各行间插入一个0*/
		/* 处理第i 行的i+2 个系数（包括一个0）*/
		for (int j = 0; j < i + 2; j++) {
			int t;
			int tmp;
			t = q.front(); /* 读取一个系数，放入t*/
			q.pop();
			tmp = s + t; /* 计算下一行系数，并进队列*/
			q.push(tmp);
			s = t; /* 打印一个系数，第i+2 个是0*/
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
