class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size(),false);
        int maxElement = *max_element(candies.begin(),candies.end());
        
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=maxElement){
                ans[i] = true;
            }
        }
        
        cout<<maxElement;
        
        return ans;
    }
};