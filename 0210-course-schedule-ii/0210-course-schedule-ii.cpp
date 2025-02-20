class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);

        for (auto preq : prerequisites) {
            adjList[preq[1]].push_back(preq[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> inStack(numCourses, false);
        vector<int> result;
        vector<int> emp;

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                stack<int> s;
                s.push(i);

                while (!s.empty()) {
                    int curr = s.top();
                    if (!visited[curr]) {
                        visited[curr] = true;
                        inStack[curr] = true;

                        for (int neighbor : adjList[curr]) {
                            if (!visited[neighbor]) {
                                s.push(neighbor);
                            } else if (inStack[neighbor]) {
                                return emp;
                            }
                        }
                    } else {
                        if (inStack[curr]) {
                            result.push_back(curr);
                            inStack[curr] = false; 
                        }
                        s.pop();
                    }
                }
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};