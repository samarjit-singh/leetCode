class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if( k == 0){
            
            return s;
            
        } else if(k > 1) {
            
            int n = s.length();
            
            char char_array[n+1];           //converting to character array
            strcpy(char_array, s.c_str());  //copying the elements to character array
            sort(char_array,char_array+n);  //stoing the character array
            
            
            string res = "";                  
            for (int i = 0; i < n; i++) {
                res = res + char_array[i];   //pasting back the elements to string
            }
            return res;
        } else if (k==1){
            string ans = s;
            for(int i=0;i<s.length();i++){
                string reorder = s.substr(i)+s.substr(0,i);
                if(ans.compare(reorder)>0){
                    ans = reorder;
                }
            }
            return ans;
        }
        
        
        return s;
    }
};