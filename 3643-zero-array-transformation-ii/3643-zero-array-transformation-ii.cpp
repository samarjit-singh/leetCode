class Solution {
public:
    bool canMakeZeroArray(const vector<int>& nums, const vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        vector<int> result = nums;

        for (int i = 0; i < k; ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            diff[l] += val;
            if(r+1 < n) diff[r + 1] -= val;
        }

        int ops = 0;
        for (int i = 0; i < n; ++i) {
            ops += diff[i];
            result[i] = max(0, result[i] - ops);
        }

        return all_of(result.begin(), result.end(), [](int x) {return x == 0; });
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if(all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) {
            return 0;
        }

        int left = 1, right = queries.size();
        int ans = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canMakeZeroArray(nums, queries, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
