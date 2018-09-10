class WordDistance {
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); i++) {
            idxs[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int minDis = INT_MAX/2;
        for (int i = 0; i < idxs[word1].size(); i++) {
            for (int j = 0; j < idxs[word2].size(); j++) {
                minDis = min(minDis, abs(idxs[word1][i] -idxs[word2][j]));
            }
        }
        return minDis;
    }
private:
    unordered_map<string, vector<int>> idxs;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
