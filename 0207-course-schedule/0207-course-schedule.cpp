class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);

        for(auto prereq: prerequisites){
            adjList[prereq[1]].push_back(prereq[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> inStack(numCourses, false);

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                stack<int> s;
                s.push(i);

                while(!s.empty()){
                    int curr = s.top();

                    if(!visited[curr]){
                        visited[curr] = true;
                        inStack[curr] = true;

                        for(auto neighbor: adjList[curr]){
                            if(!visited[neighbor]){
                                s.push(neighbor);
                            } else if(inStack[neighbor]){
                                return false;
                            }
                        }
                    } else {
                        inStack[curr] = false;
                        s.pop();
                    }
                }
            }
        }

        return true;
    }
};