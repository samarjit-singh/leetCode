/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxUncrossedLines = function(nums1, nums2) {
    const m = nums1.length;
    const n = nums2.length;
    
    const dp = new Array(m+1);
    for (let i = 0; i <= m; i++) {
    dp[i] = new Array(n + 1).fill(0);
  }
    
    for (let i = 1; i <= m; i++) {
    for (let j = 1; j <= n; j++) {
      if (nums1[i - 1] === nums2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }
    return dp[m][n];
};