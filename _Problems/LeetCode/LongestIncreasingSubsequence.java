/**
 * Author: Hung Duc Vu
 * Case Western Reserve University
 * Created: 10/14/2018
 *
 * LeetCode 300. Longest Increasing Subsequence https://leetcode.com/problems/longest-increasing-subsequence/description/
 * Difficulty: Medium. Beats 95.51% Java. O(NlogN)
 * Steps:
 * 1. s[i] is minimum last element of subsequence has length i + 1
 * 2. Binary search to find the biggest s[i] because s is always sorted
 */
class LongestIncreasingSubsequence {
    public int lengthOfLIS(int[] nums) {
        if (nums.length == 0)
            return 0;
        int[] s = new int[nums.length];
        s[0] = nums[0];
        int res = 0;
        for (int i = 1; i < nums.length; i++) {
            int l = 0;
            int r = res;
            int mid = (l + r) / 2;
            while (l < r) {
                mid = (l + r) / 2;
                if (s[mid] >= nums[i])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            if (s[l] < nums[i]) {
                s[l + 1] = nums[i];
                res = Math.max(res, l + 1);
            }
            else
                s[l] = nums[i];
        }
        return res + 1;
    }
}
