class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> umap;
        vector<int> res;

        for(auto x:nums){
            umap[x]++;
        }

        for(auto x:umap){
            pq.push({x.second,x.first});
        }

        for(int i=0;i<k;i++){
            auto top = pq.top();
            res.push_back(top.second);
            pq.pop();
        }


        return res;

    }
};