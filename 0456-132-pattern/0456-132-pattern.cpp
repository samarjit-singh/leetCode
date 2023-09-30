class Solution {
public:
    bool find132pattern(vector<int>& nums) {
       int n = nums.size();
        if (n < 3) {
            return false; // There can't be a 132 pattern with less than 3 elements.
        }

        stack<int> s;
        int s3 = INT_MIN; // Initialize the third element of the pattern.

        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < s3) {
                return true; // Found a 132 pattern.
            } else {
                while (!s.empty() && nums[i] > s.top()) {
                    s3 = s.top(); // Update s3 with the maximum value from the stack.
                    s.pop();
                }
            }
            s.push(nums[i]);
        }
        return false;
    }
};