/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* dfs(vector<vector<int>>& grid, int n, int r, int c) {
        bool allSame = true; // to check if all the cells got same value in a grid

        for(int i=0;i<n && allSame;i++) { // check if value in grid are same if not break
            for(int j=0;j<n;j++) {
                if(grid[r][c] != grid[r+i][c+j]) {
                    allSame = false;
                    break;
                }
            }
        }

        if(allSame) {
            return new Node(grid[r][c] == 1, true);
        }

        int mid = n/2;

        Node* topLeft = dfs(grid, mid, r, c);
        Node* topRight = dfs(grid, mid, r, c+mid);
        Node* bottomLeft = dfs(grid, mid, r+mid, c);
        Node* bottomRight = dfs(grid, mid, r+mid, c+mid);

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0);
    }
};