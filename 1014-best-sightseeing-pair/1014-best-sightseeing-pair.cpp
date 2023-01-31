class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int left_max = values[0];
        int maxi = INT_MIN;
        for(int i=1;i<values.size();i++){
            int sum = left_max + values[i] - i;
            maxi = max(maxi,sum);
            left_max = max(left_max, values[i]+i);
        }
        
        return maxi;
    }
};