class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9+7;
        map<char, long long> freq;
        int res = 0;

        for(auto x:s) {
            freq[x]++;
        }

        for(int i=0;i<t;i++) {
            long long temp = freq['z'];
            for(char c = 'z'; c > 'a'; c--) {
                freq[c] = freq[c-1] % MOD;

            }
            freq['a'] = temp % MOD;
            freq['b'] += temp % MOD;
        }

        long long result = 0;

        for(auto x:freq) {
            cout<<x.first<<" "<<x.second<<endl;
        }

        for(auto x:freq) {
            result += x.second;
        }
        

        return result%MOD;
    }
};

