class Solution {
public:
    
    static bool cmp(pair<string,int>& a, pair<string,int>& b){
        if(a.second == b.second){ //if freq are same
            int val = a.first.compare(b.first);
            if(val<0) return a.second;
            else 
                 b.second;
            
        }
        return a.second>b.second;
    }
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        unordered_map<string,int> umap;
        
        for(auto x:words){
            umap[x]++;
        }
        
        vector<pair<string,int>> temp;
        
        for(auto& x:umap){
            temp.push_back(x);
        }
        
        sort(temp.begin(),temp.end(),cmp);
        
        for(int i=0;i<k;i++){
            result.push_back(temp[i].first);
        }
        
        return result;
    }
};