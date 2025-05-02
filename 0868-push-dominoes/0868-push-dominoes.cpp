class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string result = dominoes;
        int i=0;

        while(i < n) {
            if (result[i] == '.') {
                int j = i;

                while(j<n && result[j] == '.') {
                    j++;
                }

                // in this case .L
                // i = 0 and j is at L right will take up value L
                // and I process right only when it has L dominoes which is the last if case

                char left = (i == 0) ? 'L' : result[i-1];
                char right = (j == n) ? 'R' : result[j];

                if(left == 'R' && right == 'L') {
                    int l = i, r = j-1;
                    while(l<r) {
                        result[l++] = 'R';
                        result[r--] = 'L';
                    } 
                } else if (left == 'R') {
                        for(int k=i;k<j;k++) result[k] = 'R';
                } else if(right == 'L') {
                        for(int k=i;k<j;k++) result[k] = 'L';
                }

                i = j;
            } else {
                i++;
            }
        }

        return result;
    }
};


// Move j until i find 'L' or 'R'
// when I find one process the dominoes between i and j depending on direction
// process left only when it has R dominoes and vice-versa