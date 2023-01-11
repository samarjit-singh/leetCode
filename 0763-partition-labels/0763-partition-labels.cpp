class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> a(26);
        int n = s.size();
        for(int i=0;i<n;i++){
            a[s[i]-'a'] = i;
        }
        
        int maxi = -1;
        int last = 0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            maxi = max(maxi,a[s[i]-'a']);
            if(i == maxi){
                ans.push_back(i-last+1);
                last = i+1;
            }
        }
        return ans;
    }
};