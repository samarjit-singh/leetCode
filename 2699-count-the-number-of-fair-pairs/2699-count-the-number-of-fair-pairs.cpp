class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int l = i + 1;
            int r = n - 1;

            // Find the first index j such that nums[i] + nums[j] >= lower
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (nums[i] + nums[mid] >= lower)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            int start = l;

            l = i + 1;
            r = n - 1;

            // Find the last index j such that nums[i] + nums[j] <= upper
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (nums[i] + nums[mid] <= upper)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            int end = r;

            if (start <= end)
                count += (end - start + 1);
        }

        return count;
    }
};
