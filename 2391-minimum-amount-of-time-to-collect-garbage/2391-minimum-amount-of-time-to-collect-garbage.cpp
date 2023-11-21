class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res = 0;
        
        for(auto g:garbage){
            res += g.length();
        }
        
        bool m = false, p = false, g = false;
        
        for(int i = travel.size(); i>0; i--){
            m = m || garbage[i].find("M") != string::npos;
            p = p || garbage[i].find("P") != string::npos;
            g = g || garbage[i].find("G") != string::npos;
            
            res += travel[i-1] * ((m ? 1 : 0)+(p ? 1 : 0)+(g ? 1 : 0));
        }
        return res;
    }
};