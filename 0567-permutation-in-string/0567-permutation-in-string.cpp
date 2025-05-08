class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(n > m) return false;

        unordered_map<char, int> s1Map, windowMap;

        // take character count of smaller string
        for(auto x:s1) {
            s1Map[x]++;
        }

        // first window from s2
        for(int i=0;i<n;i++) { 
            windowMap[s2[i]]++;
        }
        
        if(s1Map == windowMap) return true;

        for(int i=n;i<m;i++) {
            windowMap[s2[i]]++;

            char toRemove = s2[i-n];
            windowMap[toRemove]--;

            if(windowMap[toRemove] == 0) {
                windowMap.erase(toRemove);
            }

            if(s1Map == windowMap) return true;
        }

        return false;
    }
};

// if n is greater than m cannot find permutation in m