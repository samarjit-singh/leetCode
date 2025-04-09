class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i=0;
        int j=1;
        int n = nums.size();

        vector<int> res(n);

        for(auto num:nums){
            if(num > 0) {
                res[i] = num;
                i += 2;
            } else {
                res[j] = num;
                j += 2;
            }
        }

        return res;
    }
};