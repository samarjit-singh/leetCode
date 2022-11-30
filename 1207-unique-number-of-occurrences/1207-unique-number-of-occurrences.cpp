class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        
        vector<int> feq;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        
        for(auto x:mp){
            feq.push_back(x.second);
        }
        
        sort(feq.begin(),feq.end());
        
        for(int i=0;i<feq.size()-1;i++){
            if(feq[i]==feq[i+1])
                return false;
        }
        
        return true;
    }
};