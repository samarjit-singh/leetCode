class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
       sort(people.begin(), people.end());
        
        for(int i=0;i<people.size();i++){
            cout<<people[i]<<" ";
        }
        
        int result = 0;
        
        int l = 0 , r = people.size()-1;
        
        while( l <= r ){
            if(people[l]+people[r]<=limit){
                result++;
                l++;
                r--;
            } else {
                result++;
                r--;
            }
            
        }
        
        return result;
        
        return 0;
    }
};