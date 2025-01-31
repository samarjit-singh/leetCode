/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> visited;

        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        for(auto x:visited){
            cout<< x.first->val << " " << x.second->val;
        }

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            for (Node* neighbor : current->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[current]->neighbors.push_back(visited[neighbor]);
            }
        }

        return cloneNode;
    }
};