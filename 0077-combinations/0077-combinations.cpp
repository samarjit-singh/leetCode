class Solution {
public:

    void backtrack(int i, int n, vector<vector<int>>& res, vector<int>& subset, int k) {
        if(subset.size() == k){
            res.push_back(subset);
            return;
        }

        if(i > n){
            return;
        }

        subset.push_back(i);
        backtrack(i+1, n, res, subset, k);

        subset.pop_back();
        backtrack(i+1, n, res, subset, k);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> subset;
        
        backtrack(1, n, res, subset, k);

        return res;    
    }
};