class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;
        string ans = "";
        
        for(auto x:s){
            mp[x]++;
        }
        
        for(auto x:order){
            if(mp.find(x)!=mp.end()){
                auto temp = mp.find(x);
                int count = temp->second;
                string s(count,x);
                ans+=s;
                mp.erase(x);
            }
        }
        
        for(auto x:mp){
            string s(x.second,x.first);
            ans+= s;
        }
        return ans;
    }
};