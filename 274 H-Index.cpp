// Time: O(nlgn) for `sort`
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


// Space: O(n), Time:O(n) 
class Solution {
public:
    int hIndex(vector<int>& citations) {
        // the numebr of papers
        int N = citations.size();
        
        
        // denote correponding number of papers of each citation
        int count[N+1] = {0};
        for (int i = 0; i < N; i++) {
            if (citations[i] > N) {
                count[N]++;
            } else {
                count[citations[i]]++;
            }
            
        }
        
        // for (int i = 0; i < N; i++) {
        //     cout << count[i]<< " ";
        // }
        
        // accumulate the number of papers from largest to lowest citation
        for (int i = N; i >= 0; i--) {
            if (i < N) count[i] += count[i+1];
            if (count[i] >= i) {
                return i;
            }
        }
        
        return N;
    }
};

// Need to notice:
// 1. We only construct an array of consective citations of [0, N] citation, 
//   because we are aim to find a H-index, and it can't exceed the number of papers.
