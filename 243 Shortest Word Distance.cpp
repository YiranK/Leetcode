class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
		vector<int> idx1, idx2;
	    for (int i = 0; i < words.size(); i++) {
	        if (words[i] == word1) idx1.push_back(i);
	        if (words[i] == word2) idx2.push_back(i);
	    }
	    
	    int minDis = words.size()-1;
	    for (int i = 0; i < idx1.size(); i++) {
	        for (int j = 0; j < idx2.size(); j++) {
	            if (abs(idx2[j]-idx1[i]) < minDis) minDis = abs(idx2[j]-idx1[i]);
	        }
	    }
	    return minDis;
        
        
    }
};


// Better Idea: The Most Recent Occurrence
// ONE PASS
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
		// Better Idea: The Most Recent Occurrence
        int idx1 = -1, idx2 = -1, minDis = words.size()-1;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                idx1 = i;
            } else if (words[i] == word2) {
                idx2 = i;
            }
            
            if (idx1 >= 0 && idx2 >= 0) {
                minDis = min(minDis, abs(idx1-idx2));
            }
        }
        
        return minDis;
    }
};

