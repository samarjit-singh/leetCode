class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans; // make ans vector
        vector<int> temp = nums; // make a copy vector temp
        unordered_map<int,int> umap; // umap for storing the ocuurance
         
        sort(nums.begin(),nums.end(),greater<int>()); // sort array in decreasing
         
        for(int i=0;i<k;i++) 
            umap[nums[i]]++; // count the occurance
         
        for(auto it:temp){
            if(umap[it] > 0){
                ans.push_back(it);
                umap[it]--;
            }
                
        }
        
        return ans;
        
    }
};

// time complexity nlog(k)