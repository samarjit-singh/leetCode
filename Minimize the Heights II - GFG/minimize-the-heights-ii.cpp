// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        
        sort(arr,arr+n);
        int result = arr[n-1]-arr[0];
        int maximum,minimum;
        
        for(int i = 0; i < n ; i++){
            maximum = max(arr[i]+k,arr[n-1]-k);  //checking maximum between last element and all the elements
            minimum = min(arr[i+1]-k,arr[0]+k);  //checking for minimum b/w the first element and all elemnts
            
            if(minimum>=0){
                result = min(result, maximum-minimum);
            } else {
                continue;
            }
        }
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends