class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> umap1;
        unordered_map<int,int> umap2;
        vector<vector<int>> ans;
        
        for(auto x:nums1){
            umap1[x]++;
        }
        
        for(auto x:nums2){
            umap2[x]++;
        }
        
        set<int> ans1;
        for(int i=0;i<nums1.size();i++){
            if(umap2.find(nums1[i]) == umap2.end()){
                ans1.insert(nums1[i]);
            }
        }
        vector<int> vc(ans1.begin(), ans1.end());
        ans.push_back(vc);
        
        
        set<int> ans2;
        for(int i=0;i<nums2.size();i++){
            if(umap1.find(nums2[i]) == umap1.end()){
                ans2.insert(nums2[i]);
            }
        }
        vector<int> vc2(ans2.begin(), ans2.end());
        ans.push_back(vc2);
        
        return ans;
        
    }
};