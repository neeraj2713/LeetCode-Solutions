class RandomizedSet {
private:
    unordered_map<int, int> mpp;
    vector<int> v;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(mpp.count(val)) return false;
        mpp[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!mpp.count(val)) return false;
        int idx = mpp[val];
        int last = v.back();
        v[idx] = last;
        mpp[last] = idx;
        v.pop_back();
        mpp.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */