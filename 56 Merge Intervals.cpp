/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(const Interval& a, const Interval& b) {
        // if (a.start < b.start)
        //     return 1;
        // else if (a.start == b.start) 
        //     return (a.end <= b.end);
        // else 
        //     return 0;
        return (a.start < b.start);
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return vector<Interval>();
        // cout << "heng";
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<Interval> ans = {intervals[0]};
        
        // for (int i = 0; i < intervals.size(); i++) cout << intervals[i].start << intervals[i].end << endl;
        
        for (int i = 0; i < intervals.size(); i++) {
            if (ans.back().end < intervals[i].start)
                ans.push_back(intervals[i]);
            else
                ans.back().end = max(intervals[i].end, ans.back().end);
        }
        
       
        return ans;
    }
};

// error-prone points:
// 1. the comparison function must be static member function or global function, not a common member founction belongs to a class.
// 2. to visit a member variable of struct in a vector<struct> by using iterator: iter->member.
//    to visit a member variable in struct: intervals.start
// 3. if {iter = erase(iter);} else {iter++;}
// 4. wrong: while(i+1 < anss.size() && !(anss[i].end < anss[i+1].start));
//    eg. [[1,10],[4,5],[6,7],[8,9]], will get wrong result.
//    for the relationship is not just about successive two nodes' comparsion. the max end value need update.
// 5. complex logical statements in comparsion function will cause error, don't know why.

