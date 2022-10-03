class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> A = nums; // creating a copy
        
        map<int,int> mp;
        
        sort(nums.begin(),nums.end()); //sorting theoriginal vector
        
        for(int i=0;i<n;i++){
            mp.insert({nums[i],i});
        }
        
        map<int, int>::iterator itr;
        
        for (itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
        }
        
        for(int i=0;i<n;i++){
            nums[i] = mp[A[i]];
        }
        
        return nums;
    }
};