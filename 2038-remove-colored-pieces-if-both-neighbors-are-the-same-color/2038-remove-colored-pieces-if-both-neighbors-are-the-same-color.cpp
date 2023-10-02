class Solution {
public:
    bool winnerOfGame(string colors) {
        int counta = 0;
        int countb = 0;
        
        for(int i=1;i<colors.size()-1;i++){
            char current = colors[i];
            char prev = colors[i-1];
            char next = colors[i+1];
            
            if(current == 'A' && prev == 'A' && next == 'A'){
                counta++;
            } else if(current == 'B' && prev == 'B' && next == 'B'){
                countb++;
            }
        }
        
        return counta>countb;
    }
};