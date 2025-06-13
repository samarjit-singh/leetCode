class Solution {
public:
    bool isPossible(vector<int>& nums, int val, int p) {
        int count = 0;
        int i = 1;
        while(i < nums.size()) {
            if(nums[i]-nums[i-1] <= val) {
                count++;
                i+=2;
            } else {
                i+=1;
            }
        }

        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back(), mid;
        int ans = INT_MAX;

        cout<<nums.back();

        while(low <= high) {
            mid = low + (high-low) / 2;
            if(isPossible(nums, mid, p)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;
    }
};