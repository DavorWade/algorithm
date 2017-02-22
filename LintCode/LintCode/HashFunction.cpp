#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param key: A String you should hash
	* @param HASH_SIZE: An integer
	* @return an integer
	*/
	int hashCode(string key, int HASH_SIZE) {
		// write your code here
		int ans = 0;
		for (int i = 0; i < key.size();i++) {
			ans = (1LL * ans * 33 + key[i]) % HASH_SIZE;
		}

		return ans;
	}
};
