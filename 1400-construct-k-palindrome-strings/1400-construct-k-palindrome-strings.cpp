class Solution {
public:
    bool canConstruct(string s, int k) {
        
        vector<int> a(26); // make a vector to store the occurance of each character
        
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++; // insert the count in vector
        }
        
//         declare odd even counters
        int odd = 0;
        int even = 0;
        
        for(int i=0;i<26;i++){
            if(a[i]%2 != 0){ // now check for odd occurance of characters
                odd++;
            } else { // now check for even occurance of characters
                even++;
            }
        }
        
        cout<<odd<<endl;
        cout<<even;
        
        if(odd>k){
            cout<<"odd>k";
            return false;
        }
            
        if(even==k){
            cout<<"even==k";
           return true; 
        }
            
        if(s.size()<k){
            cout<<"s.size()<k";
            return false;
        }
            
        
        return true;
    }
};