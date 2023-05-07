class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n,0);
        vector<int> s;
        for(int i=0;i<n;i++){ // iterate over obstacles vector
            if(s.empty() || obstacles[i]>=s.back()){ // if s is empty or last element of s is smaller than obstacles[i]
                s.push_back(obstacles[i]); 
                ans[i] = s.size();
            } else {
                auto it = upper_bound(s.begin(),s.end(),obstacles[i]); // find the upper bound of obstacles[i]
                *it = obstacles[i]; // replace that upper bound wiht obstacles[i]
                ans[i] = it-s.begin()+1; //and in ans[i] store the difference in length
            }
        }
        return ans;
    }
};
// int the above approach we will maintain 2 vector ans and s vector