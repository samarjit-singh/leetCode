class Solution {
public:
    string largestGoodInteger(string num) {
        int result = -1;
        
        for(int i=0; i+2 < num.size();i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                result = max(result,num[i] - '0');
            }
        }
        
        cout<<result;
        
        return (result == -1) ? "" : string(3, '0'+result);
        
    }
};