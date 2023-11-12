class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<int>> umap;
        vector<string> ans;
        
        for(int x=0;x<access_times.size();x++)
            umap[access_times[x][0]].push_back(stoi(access_times[x][1]));
        
        
        for (auto x : umap) {
            sort(x.second.begin() , x.second.end());
            if(x.second.size() > 2){
                for (int i = 2; i < x.second.size(); i++) {
                    if(x.second[i]-x.second[i-2] < 100){
                        ans.push_back(x.first);
                        break;
                    }
                }
            }
        } 
    
        
        return ans;
    }
};