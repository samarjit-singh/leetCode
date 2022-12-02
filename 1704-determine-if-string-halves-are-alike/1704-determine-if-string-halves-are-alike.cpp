class Solution {
public:
    
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    
    bool halvesAreAlike(string s) {
        
        int halfLen = s.size()/2;
        
        int firstHalf = 0, secondHalf = 0;
        
        for(int i=0;i<halfLen;i++){
            if(isVowel(s[i])){
                firstHalf++;
            }
            if(isVowel(s[i+halfLen])){
                secondHalf++;
            }
        }
        
        return firstHalf == secondHalf;
        
    }
};