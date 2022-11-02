class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st{bank.begin(),bank.end()}; // putting elements of bank in unordered set
        
//         if end is now present in the set we return -1
//         count counts the occurrences of a particular element in an unordered_set container
        if(!st.count(end)){
            return -1;
        }
        
        
//         make a queue and push start on it
        queue<string> Q;
        Q.push(start);
        
//         n is number of elements present in a level
        int steps = 0,n;
        
        string curr,t;
        
        while(!Q.empty()){
            n = Q.size(); // number of strings present at that level
            while(n--){
                curr = Q.front();
                Q.pop();
                if(curr==end) 
                    return steps;
                st.erase(curr);
                for(int i = 0 ; i< 8 ; i++){
                    t = curr;
                    t[i]='A';
                    if(st.count(t)) Q.push(t);
                    t[i]='C';
                    if(st.count(t)) Q.push(t);
                    t[i]='G';
                    if(st.count(t)) Q.push(t);
                    t[i]='T';
                    if(st.count(t)) Q.push(t);
                }
            }
            steps++;
        }
        return -1;
    }
};

// We have on;y used brute force in this Q