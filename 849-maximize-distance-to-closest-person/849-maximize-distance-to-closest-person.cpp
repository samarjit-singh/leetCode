class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int prefix_zeros = -1, sufix_zeros = -1, max_zeros = -1, zeros = 0;
        
        for(int i = 0; i < seats.size();i++){
            if(seats[i]==0){
                zeros++;
            } else {
                if(prefix_zeros == -1){
                    prefix_zeros = zeros;
                } else {
                    max_zeros = max(max_zeros, zeros);
                }
                zeros = 0;
            }
        }
            sufix_zeros = zeros;
            return max(max(prefix_zeros,sufix_zeros), (max_zeros+1)/2);
        }
    
};