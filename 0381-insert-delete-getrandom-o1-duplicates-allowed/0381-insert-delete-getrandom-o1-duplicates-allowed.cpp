class RandomizedCollection {
public:
    map<int,set<int>> mp; // map the elemsts in vector with where they are present 
    vector<int> v; // for storing all the elements even the duplicates ones
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        v.push_back(val);
        mp[val].insert(v.size()-1); //element is inserted at the back of vector so we map its position with size - 1
        
        return mp[val].size()==1; // if the size of set is one return true
    }
    
    bool remove(int val) {
        auto it = mp.find(val);
        if(it!=mp.end()){
            auto pos = *it->second.begin(); // pos is an integer not a pointer
            it->second.erase(it->second.begin());
            v[pos] = v.back(); // element from the back is brought at index pos
            mp[v.back()].insert(pos); // new index of element is store in map
            mp[v.back()].erase(v.size()-1); // removing the old index
            v.pop_back();
            if(it->second.size()==0) //if no indices are present in map corresponding to val in map, it means it was present only once 
                mp.erase(it);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */