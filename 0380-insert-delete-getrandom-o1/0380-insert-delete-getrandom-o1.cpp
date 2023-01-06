class RandomizedSet { 
    vector<int> _nums;
    unordered_map<int,int> pos;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(pos.find(val)!=pos.end()){
            return false;
        }
        _nums.push_back(val);
        pos.insert({val,_nums.size()-1});
        return true;
    }
    
    bool remove(int val) {
        if(pos.find(val)==pos.end()){
            return false;
        }
        int posi = pos[val];
        _nums[posi] = _nums[_nums.size()-1];
        pos[_nums[posi]] = posi;
        _nums.pop_back();
        pos.erase(val);
        return true;
    }
    
    int getRandom() {
        return _nums[rand()%_nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */