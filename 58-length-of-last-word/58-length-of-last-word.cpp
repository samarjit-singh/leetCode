class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        reverse(s.begin(),s.end());
        
        int space = false;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' && space){
                break;
            }
            
            if(s[i]==' ' && !space ){ //if first character is the space
                continue;
            } else {
                ans++;
                space = true;
            }
        }
        return ans;
    }
};