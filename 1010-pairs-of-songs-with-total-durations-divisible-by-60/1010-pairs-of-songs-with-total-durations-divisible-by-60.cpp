class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<long long> count(60);
        for(auto i:time)
            count[i%60]++;
        
        long long result = 0;
        for(long long i=1;i<30;i++) // for 1 to 29
            result += count[i]*count[60-i];
        
        result += (count[0]*(count[0]-1))/2 + (count[30]*(count[30]-1))/2;
        
        return result;
        
    }
};