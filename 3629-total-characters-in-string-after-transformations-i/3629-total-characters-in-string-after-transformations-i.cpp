class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9+7;
        map<char, long long> freq;

        for(auto x:s) {
            freq[x]++;
        }

        for(int i=0;i<t;i++) {
            long long temp = freq['z'];
            for(char c = 'z'; c > 'a'; c--) { // in z we will store value of y 
                freq[c] = freq[c-1] % MOD;

            }
            freq['a'] = temp % MOD; // in a I'll store value of z
            freq['b'] += temp % MOD; //in b I am storing a + z
        }

        long long result = 0;

        for(auto x:freq) {
            result += x.second;
        }
        

        return result%MOD;
    }
};

// in the approach I am transerfirng the freq to next character
// after every t operations