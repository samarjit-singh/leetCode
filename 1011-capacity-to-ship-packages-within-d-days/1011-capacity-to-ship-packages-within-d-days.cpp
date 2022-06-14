class Solution {
public:
    
    bool ok(int mid,vector<int>& weights,int D){
        int n = weights.size();
        int days = 1;
        int total = 0;
        bool isValid = true;
        for(int i=0;i<n;i++){
            if(weights[i]>mid)
                isValid = false;
            if(total+weights[i]<=mid)  //mid is the total capacity of the ship
                total += weights[i];
            else {
                days++;
                total = weights[i];
            }
        }
        
        if(!isValid){
            return false;
        } else 
            return days<=D;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1;           // min days and weight
        int r = 50000*500;   // max days and weight
        while(l<r){
            int mid = (l+r)/2;
            if(ok(mid,weights,days))
                r = mid;
            else
                l = mid+1;
        }
        return l;
    }
};