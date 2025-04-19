class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();

        for(int i=0;i<n;i++) {

            int left = i+1;
            int right = n-1;

            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(nums[i]+nums[mid] >= lower) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            int start = left;

            left = i + 1;
            right = n - 1;

            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(nums[i]+nums[mid] <= upper) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            int end = right;

            if (start <= end) {
                count += (end - start + 1);
            }
        }

        return count;
    }
};