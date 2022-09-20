class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        
        int i = 0, j = 0;
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        while(i<n && j<m){
            if(nums1[i]==nums2[j]){
                int size = ans.size();
                if(size==0){
                    ans.push_back(nums1[i]);
                } else if(ans[size-1]!= nums1[i]) {
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            } else if(nums1[i]>nums2[j]){
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
};