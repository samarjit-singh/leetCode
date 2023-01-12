class Solution {
public:
    long long smallestNumber(long long num) {
        string s = to_string(abs(num));
        
        sort(s.begin(),s.end());
        
        int i = 0;
        long long res;
        if(num<=0){
            reverse(s.begin(),s.end());
            res = -stoll(s);
        } else {
            while(s[i]=='0'){
                i++;
            }
            swap(s[0],s[i]);
            res = stoll(s);
        }
        
        return res;
    }
};