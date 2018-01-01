/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
The method is really trival.
First we sort the intervals based on their "start"
For intervals[i] and interval[j],
If intervals[i].end<intervals[j].end, we merge the two intervals. Updating the merged intervals' end to be the large of the two intervals.
If not, intervals[i] and intervals[j] belong to different interval and they don't intersect.
*/
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()) return vector<Interval>{};
        sort(intervals.begin(),intervals.end(),[](Interval &a, Interval &b){ return a.start<b.start;});
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(res.back().end<intervals[i].start) res.push_back(intervals[i]);
            else res.back().end=max(res.back().end,intervals[i].end);
        }
        return res;
    }
};