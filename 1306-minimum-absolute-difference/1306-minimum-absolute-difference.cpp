class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        sort(arr.begin(),arr.end());

        int minDiff = INT_MAX;

        for(int i=1;i<arr.size();i++){
            minDiff = min(minDiff, abs(arr[i]-arr[i-1]));
        }

        for(int i=1;i<arr.size();i++){
            int a = arr[i-1];
            int b = arr[i];

            cout<<"a"<<a<<endl;
            cout<<"b"<<b<<endl;

            vector<int> temp;

            if(b - a == minDiff){
                cout<<"inside if";
                temp.push_back(a);
                temp.push_back(b);
            }
            if(!temp.empty()){
                result.push_back(temp);
            }
        }

        return result;

    }
};