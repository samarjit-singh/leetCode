class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int n = nums.size();

        vector<int> keyIndexes;
        for(int i=0;i<n;i++) {
            if(nums[i] == key) {
                keyIndexes.push_back(i);
            }
        }

        vector<bool> isKDistant(n, false);
        for(int idx:keyIndexes) {
            int start = max(0, idx-k);
            int end = min(n-1, idx+k);
            for(int i=start;i<=end;i++) {
                isKDistant[i] = true;
            }
        }

        for(int i=0;i<isKDistant.size();i++) {
            if(isKDistant[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};