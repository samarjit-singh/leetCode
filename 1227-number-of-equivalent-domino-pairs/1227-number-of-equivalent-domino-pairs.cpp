class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>, int> umap;
        int count = 0;

        for(auto x:dominoes) {
            sort(x.begin(), x.end());
            umap[x]++;
        }


        for (auto& dominoe : umap) {
            if (dominoe.second > 1) {
                count += (dominoe.second * (dominoe.second - 1)) / 2;
            }
        }

        return count;
    }
};