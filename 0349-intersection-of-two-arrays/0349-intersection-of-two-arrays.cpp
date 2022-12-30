class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        unordered_set<int> s;
        
        for(int i=0;i<n;i++){
            s.insert(nums1[i]);
        }
        
        int count = 0;
        vector<int> ans;
        
        for(int i=0;i<m;i++){
            int key = nums2[i];
            if(s.find(key) != s.end()){
                count++;
                s.erase(key);
                ans.push_back(nums2[i]);
            }
        }
        
        
        return ans;
    }
};