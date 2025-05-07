/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, map<int, map<int, multiset<int>>>& mp, int pos, int depth) {
        if(!root) return;

        mp[pos][depth].insert(root->val);

        if(root->left) {
            dfs(root->left, mp, pos-1, depth+1);
        }
        if(root->right) {
            dfs(root->right, mp, pos+1, depth+1);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;

        map<int, map<int, multiset<int>>> mp;  // pos, depth: [values at each depth]

        dfs(root, mp, 0, 0);

        for(auto& [pos, second]:mp) {
            vector<int> cur;
            for(auto& [depth, val]:second) {
                cur.insert(cur.end(), val.begin(), val.end());
            }
            res.push_back(cur);
        }

        return res;
    }
};

// in this approach make imaginary line passing through node
// single line which passes through different nodes, those nodes
// lie in same depth 