class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);

        for (auto& b : bookings) {
            int r = b[0] - 1;  
            int l = b[1] - 1;
            int reserve = b[2];

            diff[r] += reserve;
            if (l + 1 < n) diff[l + 1] -= reserve;
        }

        vector<int> ans(n, 0);
        int ops = 0;
        for (int i = 0; i < n; i++) {
            ops += diff[i];
            ans[i] = ops;
        }

        return ans;
    }
};

// there is a way to update range in a o(1) using a difference array
// ek prefix array lo and just increment the start as +1 and end+1 as -1
// look at 3355. Zero Array Transformation I