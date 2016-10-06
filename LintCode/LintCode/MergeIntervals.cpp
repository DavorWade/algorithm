#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

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
    * @param intervals: interval list.
    * @return: A new interval list.
    */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        vector<Interval> rs;
        if (intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end(), complare);

        Interval tem = intervals[0];
        for (int i = 1;i < intervals.size();i++) {
            if (tem.end >= intervals[i].start) {
                //tem.start = tem.start < intervals[i].start ? tem.start : intervals[i].start;
                tem.end = tem.end > intervals[i].end ? tem.end : intervals[i].end;
            }
            else {
                rs.push_back(tem);
                tem.start = intervals[i].start;
                tem.end = intervals[i].end;
            }
        }
        rs.push_back(tem);

        return rs;
    }

    static bool complare(Interval a, Interval b) {
        return a.start < b.start;
    }
};
