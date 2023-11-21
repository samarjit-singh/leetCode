class Solution {
public:
    
    int rev(int num) {
        int reversed = 0;
        while (num > 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return reversed;
    }
    
    int countNicePairs(vector<int>& nums) {
        const int mod = 1e9 + 7;
        unordered_map<int,int> umap;
        int count = 0;
        
        for(auto x:nums){
            int a = x - rev(x);
            int cur = umap[a];
            umap[a] = cur + 1;
            count = (count+cur)%mod;
        }
        
        return count;
    }
};