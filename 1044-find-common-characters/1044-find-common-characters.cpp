class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> umap;
        vector<string> res;

        for(auto x:words[0]) {
            umap[x]++;
        }

        for(int i=1;i<words.size();i++) {
            unordered_map<char, int> temp;
            for(auto x: words[i]) {
                temp[x]++;
            }

            unordered_map<char, int> new_map;
            for(auto& [ch,count]:umap) {
                if(temp.count(ch)) { // if chracter exist in temp
                    new_map[ch] = min(count, temp[ch]);
                }
            }
            umap = move(new_map);     
        }

        for(auto& [ch,count]:umap) {
            for(int i=0;i<count;i++) {
                res.push_back(string{ch});
            }
        }

        return res;
    }
};

// maintain a global map and compare its character and count with the temp map
// and update the global map