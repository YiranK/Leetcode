class Solution {
public:
    int shortestWordDistance(vector<string>& words, string w) {
        int idx1 = -1, idx2 = -1, minDis = words.size();
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == w) {
                idx1 = idx2;
                idx2 = i;
            }
            
            if (idx1>=0 && idx2>=0) {
                minDis = min(minDis, abs(idx1-idx2));
            }
        }
        return minDis;
    }
    
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int idx1 = -1, idx2 = -1, minDis = words.size();
        if (word1 == word2) {
            return shortestWordDistance(words, word1);
        }
        
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                idx1 = i;
            } else if (words[i] == word2) {
                idx2 = i;
            }
            
            if (idx1>=0 && idx2>=0) {
                minDis = min(minDis, abs(idx1-idx2));
            }
        }
        
        return minDis;
    }
};
