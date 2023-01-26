class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0], prev = cost[1];

        for(int i=2;i<n;i++){
            cost[i] += min(prev2,prev);
            prev2 = prev;
            prev = cost[i];
        }
        return min(cost[cost.size()-1],cost[cost.size()-2]);
    }
};