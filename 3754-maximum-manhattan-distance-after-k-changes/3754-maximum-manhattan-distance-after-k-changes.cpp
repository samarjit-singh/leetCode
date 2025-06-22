class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        int north = 0, south = 0, east = 0, west = 0;

        for(int i=0;i<s.size();i++) {
            char ch = s[i];
            if(ch == 'N') north++;
            else if(ch == 'S') south++;
            else if(ch == 'E') east++;
            else if(ch == 'W') west++;

            int x = abs(north - south);
            int y = abs(west - east);

            int MD = x + y;

            int dist = MD + min(2 * k, i + 1 - MD);
            ans = max(ans, dist);
        }

        return ans;
    }
};