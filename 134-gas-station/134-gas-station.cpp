class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        queue<int> q;
        int rem=0;
        for(int i=0;i<gas.size();i++){
            if(!q.empty()){ 
                rem=rem+gas[i]-cost[i];
                if(rem<0){
                    rem=0;
                    q.pop();
                }
            }          
            if(cost[i]<=gas[i] && (gas[i]!=0 || cost[i]!=0)){   
              if(rem==0){
                    q.push(i); 
                    rem=gas[i]-cost[i];
                } 
            }
        }
        
        if(q.empty()){
            return -1;
        }
        
        int s=gas.size();
        int curr=0;
        
        for(int i=q.front();i<s+q.front();i++){
            int acc=i%s;
            curr=curr+gas[acc]-cost[acc];
            if(curr<0){
                return -1;
            }
            
        }
        
        return q.front();
        
        
    }
};