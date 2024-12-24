class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(target - nums[i]) != umap.end()) {
                result = {nums[umap[target - nums[i]]], nums[i]};
                break;
            } else {
                umap[nums[i]] = i;
            }
        }

        return result;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end()); // Ensure the array is sorted to handle duplicates.

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for the first element.

            int target = -nums[i];
            unordered_map<int, int> seen;
            for (int j = i + 1; j < nums.size(); j++) {
                if (seen.find(target - nums[j]) != seen.end()) {
                    res.push_back({nums[i], target - nums[j], nums[j]});
                    // Skip duplicates for the second and third elements.
                    while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
                }
                seen[nums[j]] = j;
            }
        }

        return res;
    }
};
