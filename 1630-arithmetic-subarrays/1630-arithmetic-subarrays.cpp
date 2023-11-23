class Solution {
public:
    
    bool util(vector<int>& arr,int l,int r){
        sort(arr.begin(),arr.end());
        
        int diff = arr[1]-arr[0];
        
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i] != diff){
                return false;
            }
        }
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result;
        for(int i=0;i<l.size();i++){
            vector<int> curr;
            for(int j=l[i];j<=r[i];j++){
                curr.push_back(nums[j]);
            }
            bool res = util(curr,l[i],r[i]);
            result.push_back(res);
        }
        
        return result;
    }
};