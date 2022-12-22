class Solution {
public:
    
//     initially make an array to store all the 26 letter
    int unionFind[26]; //later we will recognize them with thei parents node
    
    int find(int x){
        if(unionFind[x]!=x){
            return find(unionFind[x]);
        }
        return x;
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        for(int i=0;i<26;i++){
            unionFind[i] = i;//initialze all the letters with their own value
        }
        
        for(auto e : equations){
            if(e[1] == '='){
                unionFind[find(e[0]-'a')] = find(e[3]-'a');
            }
        }
        
        for(auto e : equations){
            if(e[1] == '!' && find(e[0]-'a') == find(e[3]-'a')) return false;
        }
               
        return true;
        
    }
};