class Solution {
public:
    int balancedStringSplit(string s) {
        int countR = 0;
        int countL = 0;
        int count = 0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='R'){
                countR++;
            }
            if(s[i]=='L'){
                countL++;
            }
            
            if(countL == countR){
                count++;
                countL = 0;
                countR = 0;
            }
        }
        
        return count;
    }
};