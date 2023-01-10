class Solution {
public:
    int bitwiseComplement(int n) {
        vector<int> temp;
        
        if(n==0)
            return 1;
        
        while(n>0){
            temp.push_back(n%2);
            n = n/2;
        }
        
        for(int i=0;i<temp.size();i++){
            if(temp[i]==0)
                temp[i] = 1;
            else if(temp[i]==1)
                temp[i] = 0;
        }
        
        int res = 0;
        for(int i=temp.size()-1;i>-1;i--){
            res = res * 2 + temp[i];
        }
        
        return res;
    }
};