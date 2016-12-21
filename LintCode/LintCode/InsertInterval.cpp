#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    /**
    * Insert newInterval into intervals.
    * @param intervals: Sorted interval list.
    * @param newInterval: new interval.
    * @return: A new interval list.
    */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        vector<Interval> rs;
        Interval interval = newInterval;
        if (intervals.size() < 1) {
            rs.push_back(interval);
            return rs;
        }

        for (int i = 0; i < intervals.size(); i++) {
            if (interval.end < intervals[i].start) {
                rs.push_back(interval);
                for (int j = i; j < intervals.size(); j++) {
                    rs.push_back(intervals[j]);
                }
                break;
            }
            else if (intervals[i].end < interval.start) {
                rs.push_back(intervals[i]);
            }
            else {
                interval.start = min(interval.start, intervals[i].start);
                interval.end = max(interval.end, intervals[i].end);
            }

            if (i == intervals.size() - 1) rs.push_back(interval);
        }

        return rs;
    }
};
