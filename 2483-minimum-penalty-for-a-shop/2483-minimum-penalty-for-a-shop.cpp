class Solution {
public:
    int bestClosingTime(string customers) {
        int score = 0, best_score = 0, best_hour = -1;
        for(int i=0;i<customers.size();i++){
            if(customers[i] == 'Y'){
                score++;
            } else {
                score--;
            }
            if(score>best_score){
                best_score = score;
                best_hour = i;
            }
        }
        return best_hour+1;
    }
};