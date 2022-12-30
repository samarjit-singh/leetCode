class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        map<int,int> mp;
        
        for(auto x:arr1){
            mp[x]++;
        }
        
        for(auto temp:arr2){
            if(mp.find(temp)!=mp.end()){ // if mp is presnet in map
                auto x = mp.find(temp);
                int count = x->second;
                // while(count){
                //     ans.push_back(x->first);
                //     x--;
                // }
                vector<int>v(count,temp);
                ans.insert(ans.end(),v.begin(),v.end()); //start inserting from the end of vector
                mp.erase(temp);
            }
        }
        for(auto x:mp){
            int ele = x.first;
            int count = x.second;
            vector<int>v(count,ele);
            ans.insert(ans.end(),v.begin(),v.end());
        }
        
        return ans;
    }
};