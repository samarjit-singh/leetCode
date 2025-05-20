class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1, 0);

        for(auto& q:queries) {
            int r = q[0], l = q[1];

            diff[r] += 1;
            if(l+1 < n) diff[l+1] -= 1;
        }

        for(int i=0;i<diff.size();i++) {
            cout<<diff[i]<<" ";
        }

        int ops = 0;
        int count = 0;

        for(int i=0;i<n;i++) {
            ops += diff[i];
            nums[i] -= ops;
            if(nums[i] <= 0) count++;
        }

        return n == count;
    }
};

// there is a way to update range in a o(1) using a difference array
// ek prefix array lo and just increment the start as +1 and end+1 as -1
// 