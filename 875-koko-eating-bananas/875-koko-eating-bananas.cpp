class Solution {
public:
    bool canEat(int speed,int available_hours,vector<int>& piles){
        for(auto& bananas:piles){
            int required_hours = (bananas+speed-1)/speed; //finding the ceiling value
            if(required_hours > available_hours)
                return false;
            else
               available_hours -= required_hours;
        } 
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = *max_element(piles.begin(),piles.end()),ans;
        while(start<=end){
            int mid = (start+end)/2;
            if(canEat(mid,h,piles)){
                ans = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return ans;
    }
};