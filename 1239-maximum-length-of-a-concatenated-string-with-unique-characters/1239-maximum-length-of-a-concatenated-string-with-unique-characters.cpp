class Solution {
public:
    
    bool compare(vector<int>& selected, string& currString){
        
//         for checking the repeated characters in the current string
        vector<int> selfCheck(26,0);
        for(int i=0;i<currString.size();i++){
            if(selfCheck[currString[i]-'a']==1) return false;
            selfCheck[currString[i]-'a'] = 1;
        }
        
//      for checking the repeated characters in selected vector
        
        for(int i=0;i<currString.size();i++){
            if(selected[currString[i]-'a']==1) return false;
        }
        
        return true;
    }
    
    int help(int i,vector<string>& arr,vector<int>& selected,int len){
        
        if(i==arr.size()){
            return len;
        }
        
        string currString = arr[i];
        
        if(compare(selected,currString)==false){
            return help(i+1,arr,selected,len);
        } else {
//             pick
            for(int j=0;j<currString.size();j++){
                selected[currString[j]-'a']=1;
            }
            len += currString.size();
            int opt1 = help(i+1,arr,selected,len);
//             drop
            for(int j=0;j<currString.size();j++){
                selected[currString[j]-'a']=0;
            }
            len -= currString.size();
            int opt2 = help(i+1,arr,selected,len);
            
            
            return max(opt1,opt2);
        }
        
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> selected(26,0);
        return help(0,arr,selected,0);
    }
};