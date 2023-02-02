class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax[n]; // store all the maximum element while comparing from left to right
        lmax[0] = height[0];  // store the first element
        
        for(int i=1;i<n;i++){ 
            int temp = max(height[i],lmax[i-1]); // find the maximum ele b/w the element and the left element 
            lmax[i] = temp; // store the max ele in lmax
        }
        
        int rmax[n]; // store all the maximum element while comparing from right to left
        rmax[n-1] = height[n-1]; // store the last element
        
        for(int i=n-2;i>=0;i--){
            int temp = max(height[i],rmax[i+1]); // find the max ele b/w the ele and the right ele 
            rmax[i] = temp; // store that in rmax
        }
        
        int water = 0; // make a variable water
        
        for(int i=1;i<n-1;i++){ // traverse the height array from second ele to the second last ele
            water += min(lmax[i],rmax[i]) - height[i]; // fidnthe min ele from lmax and rmax and subtract thta from height and add it in water
        }
        
        return water; // return water
        
    }
};