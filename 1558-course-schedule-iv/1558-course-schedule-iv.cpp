class Solution {
public:

    void dfs(int course, unordered_map<int, unordered_set<int>>& prereqMap, vector<vector<int>>& graph, vector<bool>& visited) {
        if(visited[course]) return;
        visited[course] = true;

        for(auto next:graph[course]){
            dfs(next, prereqMap, graph, visited);
            prereqMap[course].insert(next);
            prereqMap[course].insert(prereqMap[next].begin(), prereqMap[next].end());
        }

    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, unordered_set<int>> prereqMap;
        vector<vector<int>> graph(numCourses);

        for(auto pre:prerequisites){
            graph[pre[0]].push_back(pre[1]);
        }

        vector<bool> visited(numCourses, false);
        for(int i=0;i<numCourses;i++){
            dfs(i, prereqMap, graph, visited);
        }

        vector<bool> answer;

        for(auto query:queries){
            answer.push_back(prereqMap[query[0]].count(query[1]));
        }

        return answer;
    }
};