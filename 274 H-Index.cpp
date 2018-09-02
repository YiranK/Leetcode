class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        // `i` denotes the number of papers whose citation is larger than `citations[i]`. (larger than, not at least)
        // during `for` loop, we can know for each citation number, how many papers' citation is larger than it.
        for (int i = 0; i < citations.size(); i++) {
            if (i >= citations[i]) return i;
        }
        return citations.size();
    }
};

// We need to redefine the definition of H-index to :
// 'for a citation number h, the number of papers whose citation is at least h, is larger than or equal to h.?
