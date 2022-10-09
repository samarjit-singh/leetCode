class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(); //find out the size of giver vector
        vector<bool>visited(n,false); // make a vector to mark visited or not visited, initialized with false
        
        queue<int>q; // make a queue for storing the keys
        q.push(0); // push 0 in it because 0 is laready visisted
        visited[0] = true; // mark visited as 0 
        
        while(!q.empty()){
            int room = q.front();
            q.pop();
            
            for(auto key:rooms[room]){
                if(visited[key]==false){
                    visited[key] = true;
                    q.push(key);
                }   
            }   
        }
        
        for(auto x : visited){
            if(x==false){
                return false;
            }
        }
        return true;
    }
};