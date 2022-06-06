class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size();
        int count = 0, sum1 = 0, sum2 = 0;
        for(int i = 0;i < n;i++){
            sum1 += flips[i]-1;
            sum2 += i;
            
            if(sum1 == sum2){
                count++;
            }
        }
        return count;
    }
};