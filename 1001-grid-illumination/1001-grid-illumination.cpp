class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> ans;
        
        if(n==0){
            return ans;
        }
        
        unordered_map<int,int> x;
        unordered_map<int,int> y;
        unordered_map<int,int> p_diag;
        unordered_map<int,int> s_diag;
        
        set<pair<int,int>> s;
        
        for(auto lamp : lamps){
            if(s.find({lamp[0],lamp[1]}) == s.end()){
                x[lamp[0]]++;
                y[lamp[1]]++;
                p_diag[lamp[0]+lamp[1]]++;
                s_diag[lamp[0]-lamp[1]]++;

                s.insert({lamp[0],lamp[1]});
            }
            
            
        }
        
        for (auto q:queries){
            if(x[q[0]]>0 || y[q[1]]>0 || p_diag[q[0]+q[1]]>0 || s_diag[q[0]-q[1]]>0){
                
                ans.push_back(1);
                
                for(int j=-1;j<=1;j++){
                    for(int k =-1; k<=1;k++){
                        int qx = q[0]+j;
                        int qy = q[1]+k;
                        
                        if(qx >= 0 and qx<n and qy>=0 and qy<n and s.count({qx,qy})){
                            s.erase({qx,qy});
                            x[qx]--;
                            y[qy]--;
                            p_diag[qx+qy]--;
                            s_diag[qx-qy]--;
                        }
                    }
                }
            } else {
                ans.push_back(0);
            }
            
        }
        return ans;
    }
};