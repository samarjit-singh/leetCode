class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigsNeeded = (minutesToTest / minutesToDie) + 1;
        
        int left = 0, right = 1000;
        
        while(left<right){
            
            int mid = left + (right-left) / 2;
            if(pow(pigsNeeded,mid) < buckets){
                left = mid+1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};