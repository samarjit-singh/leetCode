class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sol;
        set<int> numsSet;

        for (int i=0;i<nums.size();i++){
            numsSet.insert(nums[i]);
        }

        for(int i=1;i<nums.size()+1;i++){
            if (numsSet.find(i) == numsSet.end()) {
                sol.push_back(i);
            }
        }

        return sol;
    }
};