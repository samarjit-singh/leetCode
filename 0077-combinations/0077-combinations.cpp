class Solution {
public:

    void backtrack(int x,int n, int k,vector<vector<int>> &res, vector<int> &curr){
        if(curr.size() == k) {
            res.push_back(curr);
        }

        for(int i=x;i<=n;i++){
            curr.push_back(i);
            backtrack(i+1, n, k, res, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;

        backtrack(1, n, k,res,curr);

        return res;
    }
};