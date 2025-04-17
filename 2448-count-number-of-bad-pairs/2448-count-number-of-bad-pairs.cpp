class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long good_pair = 0;
        unordered_map<int, int> umap;

        for(int i=0;i<nums.size();i++) {
            good_pair += umap[nums[i] - i];
            umap[nums[i] - i] ++;
        }

        return (n * (n - 1)) / 2 - good_pair;
    }
};