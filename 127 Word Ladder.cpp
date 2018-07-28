/*
My notice:
1. "Only one letter can be changed at a time." means "every time". every time of transform you can change a letter.
2. it's a process of transform, and "Each transformed word must exist in the word list", so the 'endWord' must in the word list,
   while "beginWord is not a transformed word".
3. it's a process of breadth-first process, because every time you change a letter(whatever the letter is), you get a batch of words,
   which can be considered as a level of nodes.
*/


class Solution {
public:
    bool cmpDiff(string a, string b) {
        int diffCount = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) diffCount++;
        }
        if (diffCount == 1) return true;
        return false;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordDict) {
        if (find(wordDict.begin(), wordDict.end(), endWord) == wordDict.end()) return 0;
        // initialize 'dist' to be 2, for two nodes, 'beginWord' and 'endWord'.
        int dist = 2;
        
        // 'toVisit' is a level of nodes.
        queue<string> toVisit;
        toVisit.push(beginWord);
        vector<string> wordList(wordDict); // to avoid the reference 'wordDict' changed.
        
        // when 'toVisit' is empty, there is no more level of nodes to visit
        while (!toVisit.empty()) {
            int toVisitSize = toVisit.size();
            
            // to traverse each node of current level
            while (toVisitSize--) {
                string transWord = toVisit.front();
                toVisit.pop();  
                
                // traverse 'wordList', if there is only one letter different between 'wordList[i]' and 'transWord',
                // then erase 'wordList[i]', for we want the shortest path,
                // since we can reach this node 'wordList[i]' in current step, it's not neccessary visit it in next step.
                for (int i = 0; i < wordList.size(); i++) {
                    //cout << "ith: " << i << " " << wordList[i];          
                    if (cmpDiff(wordList[i], transWord)) {
                        //cout << " cmp difference: " << wordList[i] << " " << transWord;
                        
                        // 'endWord' must in 'wordList', but only when the requirement is met we can visit it.
                        // the requirement is that it has only one letter different from one of last level nodes.
                        if (wordList[i] == endWord) return dist;
                        
                        
                        toVisit.push(wordList[i]);
                        wordList.erase(wordList.begin()+i);
                        
                        i--; // for every time 'erase', the index will change, we need minus 1 from i;
                    }
                    //cout << endl;
                }
                //cout <<endl;
            }
            dist++;
            
        }
        return 0;
    }
};
