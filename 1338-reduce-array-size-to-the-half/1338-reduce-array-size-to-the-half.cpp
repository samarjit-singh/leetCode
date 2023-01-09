class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        priority_queue<int> pq;
        
        for(auto x:arr){
            mp[x]++;
        }
        
        for(auto x:mp){
            pq.push(x.second);
        }
        
        int ele = 0, counter = 0;
        
        while(!pq.empty()){
            ele += pq.top();
            pq.pop();
            counter++;
            
            if(ele>=n/2){
                return counter;
            }
        }
        
        return 0;
    }
};