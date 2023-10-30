class Solution {
public:
    
    static bool compare(int a,int b){
        int countOneInA = __builtin_popcount(a);
        int countOneInB = __builtin_popcount(b);
        
        if(countOneInA == countOneInB){
            return a<b;
        }
        
        return countOneInA<countOneInB;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        
        return arr;
    }
};