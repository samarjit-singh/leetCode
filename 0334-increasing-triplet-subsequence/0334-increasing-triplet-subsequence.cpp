class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int p1 = INT_MAX , p2 = p1;
        
        for(auto &x: nums){
            if(x<=p1)
                p1 = x;
            else if(x<=p2)
                p2 = x;
            else 
                return true;
        }
        
        return false;
    }
};