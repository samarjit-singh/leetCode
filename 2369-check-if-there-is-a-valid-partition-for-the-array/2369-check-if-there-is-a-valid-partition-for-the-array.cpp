class Solution {
public:
    
    bool validPrefix(int index, vector<int> &nums, vector<int> &dp) {
       	    if (index < 0)
       	        return 1;//Empty subarray case
       	    if (dp[index] != -1)
       	        return dp[index];//Already solved
       	    bool twoIdentical = 0;
       	    bool threeIdentical = 0;
            bool increasingSeq = 0;
                
            //Slef-Explanatory
      	    if (index > 0 && nums[index] == nums[index - 1])
       	        twoIdentical = validPrefix(index - 2, nums, dp);
            //2 elems mil gaye valid to ab index-2 pe search karenge
   	        if (index > 1 && nums[index] == nums[index - 1] && nums[index - 1] == nums[index - 2])
      	        threeIdentical = validPrefix(index - 3, nums, dp);
            //3 elems mil gaye valid to ab index-3 pe search karenge.
       	    if (index > 1 && nums[index] == nums[index - 1] + 1 && nums[index - 1] == nums[index - 2] + 1)
                increasingSeq = validPrefix(index - 3, nums, dp);
   	        return dp[index] = twoIdentical || threeIdentical || increasingSeq;
    }
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
       	vector<int> dp(n, -1);
       	return validPrefix(n - 1, nums, dp);
    }
};