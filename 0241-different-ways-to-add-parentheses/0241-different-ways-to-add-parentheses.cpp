class Solution {
public:
    
    vector<int> recursion(string s){
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*'){
                vector<int> ans1 = recursion(s.substr(0,i));
                vector<int> ans2 = recursion(s.substr(i+1));
                for(int k=0;k<ans1.size();k++){
                    for(int j=0;j<ans2.size();j++){
                        if(s[i] == '+') 
                            ans.push_back(ans1[k]+ans2[j]);
                        else if(s[i] == '-') 
                            ans.push_back(ans1[k]-ans2[j]);
                        else 
                            ans.push_back(ans1[k]*ans2[j]);
                    }
                }
            }
        }
        if(ans.size() == 0) ans.push_back(stoi(s));
        
        return ans;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        return recursion(expression);
    }
};