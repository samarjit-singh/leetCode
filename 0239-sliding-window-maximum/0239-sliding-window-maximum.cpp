class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> result;
        int maxEle = INT_MIN;

        for(int i=0;i<k;i++) {
            if(nums[i] > maxEle) {
                maxEle = nums[i];
            }
        }

        result.push_back(maxEle);

        for(int right=k;right<n;right++) {
            int left = right - k + 1;
            
            if(nums[left-1] == maxEle) {
                maxEle = *max_element(nums.begin() + left, nums.begin() + right + 1);
            } else {
                maxEle = max(maxEle, nums[right]);
            }

            result.push_back(maxEle);
        }

        return result;
    }
};