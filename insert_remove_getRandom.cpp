class RandomizedSet {
public:
    /** Initialize your data structure here. */
    map<int,int> m;
    vector<int> list;
    
    RandomizedSet() {
     m.clear();
    list.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val)!=m.end()) return false;
        list.push_back(val);
        m[val]=list.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val)==m.end()) return false;
        m[list.back()]=m[val];
        swap(list[m[val]],list[list.size()-1]);
        list.pop_back();
        m.erase(val);
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx=rand() % (list.size());
        return list[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */