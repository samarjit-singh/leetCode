class Solution {
public:

    int sumOfSubset(vector<int>& subset) {
        int sum = 0;

        for(int i=0;i<subset.size();i++){
            sum += subset[i];
        }

        return sum;
    }

    void backtrack(int i, vector<int>& candidates, vector<vector<int>>& res, vector<int>& subset, int target) {
        if(sumOfSubset(subset) == target){
            res.push_back(subset);
            return;
        }

        if(i >= candidates.size() || sumOfSubset(subset) > target) {
            return;
        }

        subset.push_back(candidates[i]);
        backtrack(i+1, candidates, res, subset, target);

        subset.pop_back();

        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }

        backtrack(i+1, candidates, res, subset, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int>> res;
       vector<int> subset;
       sort(candidates.begin(),candidates.end());
       backtrack(0, candidates, res, subset, target);

       return res; 
    }
};