class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
//         int start = 0;
//         int end = nums.size()-1;
//         vector<int> ans = {-1,-1};
        
        
// //         first occurance
//         while(start<=end){
//             int mid = start + (end-start) / 2;
//             if(nums[mid] < target)
//                 start = mid+1;
//             else if(nums[mid] > target)
//                 end = mid-1;
//             else {
//                 if(mid==start || nums[mid]!=nums[mid-1]){
//                     ans[0] = mid;
//                     break;
//                 } else {
//                     end = mid - 1;
//                     ans[0] = mid - 1;
//                 }
//             }
//         }
// //         last occurance
//         start = 0, end = nums.size()-1;
//         while(start <= end){
//             int mid = start + (end-start) / 2;
//             if(nums[mid] < target)
//                 start = mid+1;
//             else if(nums[mid] > target)
//                 end = mid-1;
//             else {
//                 if(mid==start ||nums[mid]!=nums[mid+1] ){
//                     ans[1] = mid;
//                     break;
//                 } else {
//                     start = mid+1;
//                     ans[1] = mid+1;
//                 }
//             }
//         }
//         return ans;
        int s = 0, e = a.size()-1;
	vector<int> ans(2, -1);
	//first occurrence
	while(s <= e){
		int m = s + (e-s)/2;
		if(a[m] < target)
			s = m+1;
		else if(a[m] > target)
			e = m-1;
		else{
			if(m == s || a[m] != a[m-1]){
				ans[0] = m;
				break;
			}
			else{
				e = m-1;
				ans[0] = m-1;
			}
		}
	}

	//last occurrence
	s = 0, e = a.size()-1;
	while(s <= e){
		int m = s + (e-s)/2;
		if(a[m] < target)
			s = m+1;
		else if(a[m] > target)
			e = m-1;
		else{
			if(m == e || a[m] != a[m+1]){
				ans[1] = m;
				break;
			}
			else{
				s = m+1;
				ans[1] = m+1;
			}
		}
	}
	return ans;
    }
};