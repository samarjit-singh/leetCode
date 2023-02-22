class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;
        
        for(auto x:nums){
            umap[x]++;
        }
        
        for(auto x:umap){
            cout<< x.first <<" "<< x.second<<endl;
            if(x.second==1)
                return x.first;
        }
        
        return 0;
    }
};