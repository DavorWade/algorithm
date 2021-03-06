#include <stdlib.h>
#include <stdint.h>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*
    * @param numbers : An array of Integer
    * @param target : target = numbers[index1] + numbers[index2]
    * @return : [index1+1, index2+1] (index1 < index2)
    * @date: 2016-8-4
    * @Complexcity: O(n) Space, O(nlogn) Time
    */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        set<int> rs;
        vector<int>::iterator iter;
        int tem;

        for (int i = 0; i < nums.size(); i++) {
            tem = target - nums[i];
            iter = find(nums.begin(), nums.end(), tem);
            if (iter != nums.end()) {
                rs.insert(i + 1);
                break;
            }
        }

        if (!rs.empty()) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == tem) {
                    rs.insert(i + 1);
                }
            }
        }

        return vector<int>(rs.begin(), rs.end());
    }
};

class Solution_map {
public:
    /*
    * @param numbers : An array of Integer
    * @param target : target = numbers[index1] + numbers[index2]
    * @return : [index1+1, index2+1] (index1 < index2)
    */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) m[nums[i]] = i;
        for (int i = 0; i < nums.size(); ++i) {
            int t = target - nums[i];
            if (m.count(t) && m[t] != i) {
                return{ i + 1, m[t] + 1 };
            }
        }
        return{};
    }
};
