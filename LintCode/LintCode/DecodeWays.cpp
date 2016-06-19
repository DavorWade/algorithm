#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param s a string,  encoded message
	* @return an integer, the number of ways decoding
	*/
	int numDecodings(string& s) {
		// Write your code here
		vector<int> dp(s.size() + 1, 0);
		dp[1] = 1;
		for (int i = 2; i <= s.size(); i++) {
			string tem;
			char *dig;
			tem.append(s, i-1, 2);
			strcpy(dig, tem.c_str());
			int tem_digtial = atoi(dig);
			if (tem_digtial > 26) dp[i] = dp[i - 1];
			else dp[i] = dp[i - 1] + dp[i - 2];
		}

		return dp[s.size()];
	}
};

int main(int argc, char *argv[]) {
	string s = "12";
	Solution sol;
	int rs = sol.numDecodings(s);
	printf("%d", rs);

	printf("\n");
	system("pause");
	return 0;
}
