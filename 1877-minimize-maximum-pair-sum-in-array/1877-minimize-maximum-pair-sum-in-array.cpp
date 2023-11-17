class Solution {
public:
    int minPairSum(vector<int>& nums) {
        vector<vector<int>> pairs;
        
        sort(nums.begin(),nums.end());
        
        int i = 0;
        int j = nums.size() -1;
        
        while(i<j){
            vector<int> cur;
            cur.push_back(nums[i]);
            cur.push_back(nums[j]);
            pairs.push_back(cur);
            i++;
            j--;
        }
        
        int maxEle = -1;
        for(int i=0;i<pairs.size();i++){
            maxEle = max(maxEle,pairs[i][0]+ pairs[i][1]);
        }
        
        return maxEle;
    }
};