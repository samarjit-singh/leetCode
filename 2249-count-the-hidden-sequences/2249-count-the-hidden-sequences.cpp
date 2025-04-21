class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long max_sum = 0, min_sum = 0, curr = 0;

        for(auto diff:differences) {
            curr += diff;
            min_sum = min(min_sum, curr);
            max_sum = max(max_sum, curr);
        }

        long min_start = lower - min_sum;
        long max_start = upper - max_sum;

        if (min_start > max_start) return 0;

        return max_start - min_start + 1;
    }
};