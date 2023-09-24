class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> curr_row(1,poured);
        
        for(int i=0;i<=query_row;i++){
            vector<double> next_row(i+2,0);
            for(int j=0;j<=i;j++){
                if(curr_row[j]>=1){
                    next_row[j] += (curr_row[j]-1)/2.0;
                    next_row[j+1] += (curr_row[j]-1)/2.0;
                    curr_row[j] = 1;
                }
            }
            if(i!=query_row){
                curr_row = next_row;
            }
        }
        
        return curr_row[query_glass];
    }
};