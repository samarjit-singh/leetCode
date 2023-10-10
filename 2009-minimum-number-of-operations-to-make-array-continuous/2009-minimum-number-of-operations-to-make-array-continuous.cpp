class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int uniqueLen = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[uniqueLen++] = nums[i];
            }
        }
        
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";    
        }
        cout<<endl;
        cout<<uniqueLen;
        
        int ans = nums.size();

        for (int i = 0, j = 0; j < uniqueLen;i++) {
            while (j < uniqueLen && nums[j] - nums[i] <= nums.size() - 1) {
                j++;
            }
            ans = min(ans, int(nums.size()) - (j - i));
        }

        return ans;
    }
};
