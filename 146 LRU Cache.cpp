class LRUCache {
private:
    unordered_map<int, int> lru;
    int cap;
    unordered_map<int, int> age;
    int age_max;
    int age_min;
public:
    LRUCache(int capacity) {
        lru.clear();
        cap = capacity;
        age_max = -1;
        age.clear();
        age_min = 0;
    }
    
    int get(int key) {
        if (lru.find(key) != lru.end()) {
            age[key] = ++age_max;
            // cout << "get key: " << key << " " << lru[key] << " age: " << age[key] << endl;
            return lru[key];
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (lru.find(key) != lru.end()) {
            lru[key] = value;
            age[key] = ++age_max;
        } else if (cap) {
            lru[key] = value;
            age[key] = ++age_max;
            cap--;
        } else if (!cap) {
            // cout << cap;
            unordered_map<int, int>::iterator it = age.begin(), itrm;
            unordered_map<int, int>::iterator itlru = lru.begin(), itlrurm;
            // cout << 1;
            int minage = INT_MAX;
            for(; it != age.end() && itlru != lru.end(); it++, itlru++) {
                // cout << it->first << " " << it->second << " " << age_max <<endl;
                // cout << age_max - cap << endl;
                if (it->second < minage) {
                    // int x = distance(it, age.begin());
                    // cout << x;
                    // cout << "erase: " << itlru->first << " " << itlru->second << endl;
                    itrm = it;
                    itlrurm = itlru;
                    minage = it->second;
                    // break;
                }
            }
            lru.erase(itlrurm);
            age.erase(itrm);
            // for (int i = 0; i < age.size(); i++) {
            //     if (age[i].second == age_max) {
            //         lru.erase(lru.begin()+i);
            //         age.erase(age.begin()+i);
            //         break;
            //     }
            // }
            lru[key] = value;
            age[key] = ++age_max;
        }
        // cout << key << " : " << value << " max_age:" << age_max << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */