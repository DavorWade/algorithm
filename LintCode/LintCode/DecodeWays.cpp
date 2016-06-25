#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
	/**
	* @param s a string,  encoded message
	* @return an integer, the number of ways decoding
	* dp[i] represent the ways of decoding from 1 to i.
	*/
	int numDecodings(string& s) {
		// Write your code here
		if (s.empty() || s[0] == '0') return 0;
		vector<int> dp(s.size() + 1, 0);
		dp[0] = dp[1] = 1;

		for (unsigned int i = 2; i <= s.size(); i++) {
			if (s[i - 1] != '0') {
				dp[i] = dp[i - 1];
			}

			if (s[i - 2] != '0') {
				string tem;
				char *dig = new char[3];
				int tem_digtial;

				tem.append(s, i - 2, 2);
				strcpy(dig, tem.c_str());
				tem_digtial = atoi(dig);

				if (tem_digtial <= 26) {
					dp[i] += dp[i - 2];
				}
			}
		}

		return dp[s.size()];
	}
};

/*
int main(int argc, char *argv[]) {
	string s = "11111878787676172120121101212918291829819";
	Solution sol;
	int rs = sol.numDecodings(s);
	printf("%d", rs);

	printf("\n");
	system("pause");
	return 0;
}
*/