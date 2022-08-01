class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        queue<char> que;
        
        for(int i=0;i<s.size();i++){
            if(!mp[s[i]]){
                mp[s[i]] = i+1;
                que.push(s[i]);
            } else {
                mp[s[i]] = -1;
            }
        }
        while(!que.empty()){
            if(mp[que.front()] != -1){
                return mp[que.front()]-1;
            
            }
            que.pop();
        }
        return -1;
    }
};