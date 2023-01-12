class Solution {
public:
    
    static bool cmp(string str1, string str2){
        return str1+str2 > str2+str1;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        
        for(int i=0;i<nums.size();i++){
            v.push_back(to_string(nums[i]));
        }
        
        sort(v.begin(),v.end(),cmp);
        
        string ans = "";
        
        for(int i=0;i<v.size();i++){
            ans += v[i];
        }
        
        // if nums contains all element "0"
        while(ans[0] == '0' && ans.length() > 1) ans.erase(0,1);
        
        
        return ans;
    }
};