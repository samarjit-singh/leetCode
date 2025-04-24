class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int count = 0;

        set<int> s(nums.begin(), nums.end());
        int ditinctCount = s.size(); // count of distinct elements in set

        for(int right=0;right<nums.size();right++) { 
            unordered_set<int> seen;
            int left = right;

            while (left < nums.size()) {
                seen.insert(nums[left]);
                if(seen.size() == ditinctCount) {
                    count++;
                }
                left++;
            }
        }

        return count;
    }
};

// for each right ele go to left till end
// creat a new set for each iteration and check its size