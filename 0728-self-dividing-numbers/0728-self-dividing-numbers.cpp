class Solution {
public:
    
    bool isValid(int num){
        int n = num,rem;
        
        while(n!=0){
            rem = n%10;
            if(rem == 0 || num%rem!=0)
                return false;
            n/=10;
        }
        return true;
    }
    
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        
        for(int i=left;i<=right;i++){
            if(isValid(i))
                ans.push_back(i);
        }
        
        return ans;
    }
};