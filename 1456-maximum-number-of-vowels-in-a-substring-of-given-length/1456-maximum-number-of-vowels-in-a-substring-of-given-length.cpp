class Solution {
public:
    int maxVowels(string s, int k) {
        
        int count = 0;
        
        for(int i=0;i<k;i++){
            if(s[i] == 'a'||s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                count++;
            }
        }
        int answer = count;
        for(int i=k;i<s.size();i++){
            int si = 0;
            if(s[i] == 'a'||s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                si++;
            }
            int sk = 0;
            if(s[i-k] == 'a'||s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u'){
                sk++;
            }
            count += si-sk;
            answer = max(answer,count);
        }
        
        return answer;
    }
};