# interview_qs
Interview questions

- https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/</br>
    Given an integer array nums and an integer k, return the maximum length of a subarray that sums to k. If there is not one, return 0 instead.</br>
    Example 1:</br>
    Input: nums = [1,-1,5,-2,3], k = 3</br>
    Output: 4</br>
    Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.</br>
    Example 2:</br>
    Input: nums = [-2,-1,2,1], k = 1</br>
    Output: 2</br>
    Explanation: The subarray [-1, 2] sums to 1 and is the longest.</br>
    <b>Map of prefix-sum vs index of prefix sum. As map is created, check if currPrefixSum-k can be found in the map, maxLen = max(maxLen, i-map[currPrefixSum-k]+1. Also, make sure to add 0->-1 in the map.</b></br>
    https://github.com/mshenoy2481/interview_qs/blob/master/leetcode325.cpp</br>

- https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/</br>
  Given a binary array data, return the minimum number of swaps required to group all 1’s present in the array together in any place in the array.</br>
  Example 1:</br>
  Input: data = [1,0,1,0,1]</br>
  Output: 1</br>
  Explanation: There are 3 ways to group all 1's together:</br>
  [1,1,1,0,0] using 1 swap.</br>
  [0,1,1,1,0] using 2 swaps.</br>
  [0,0,1,1,1] using 1 swap.</br>
  The minimum is 1.</br>
  Example 2:</br>
  Input: data = [0,0,0,1,0]</br>
  Output: 0</br>
  Explanation: Since there is only one 1 in the array, no swaps are needed.</br>
  Example 3:</br>
  Input: data = [1,0,1,0,1,0,0,1,1,0,1]</br>
  Output: 3</br>
  Explanation: One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].</br>
  <b>Sliding window. Calculate the number of 1s in the array - thats the window size. Aim is to get all 1's in the window and minimize the slips needed for that. Move that window from start to end keeping track of the 0s to flip at every start index. Minimum of those flips is the answer.</b></br>
  https://github.com/mshenoy2481/interview_qs/blob/master/leetcode1151.cpp</br>

- https://leetcode.com/problems/search-in-rotated-sorted-array-ii/</br>
  There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).</br?
  Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].</br>
  Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.</br>
  You must decrease the overall operation steps as much as possible.</br>
  <b>Binary search. There are 4 conditions where binary search is possible:</br>
       - nums[l] <= target && target < nums[m]</br>
       - nums[m] < target && target <= nums[r]</br>
       - nums[m] > nums[r] && nums[m] < target</br>
       - nums[l] > nums[m] && nums[m] > target</br>
    If any of these conditions are met, it is possible to reduce search space to half. If not, search on both sides.</b></br>
    https://github.com/mshenoy2481/interview_qs/blob/master/leetcode81.cpp</br>

- https://leetcode.com/problems/longest-valid-parentheses/</br>
  Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.</br>
  Example 1:</br>
  Input: s = "(()"</br>
  Output: 2</br>
  Explanation: The longest valid parentheses substring is "()".</br>
  Example 2:</br>
  Input: s = ")()())"</br>
  Output: 4</br>
  Explanation: The longest valid parentheses substring is "()()".</br>
  Example 3:</br>
  Input: s = ""</br>
  Output: 0</br>
  <b>Two ways:
    1. Using stack while iterating over the string. Push -1 on stack before iteration. If next char is (, push its index on the stack. If next char is ), if stack top points to (, pop from stack and maxLen is max(maxLen, i-stacktop), else push char index on stack.</br>
    2. Without stack - Iterating forward over the string, count '(' and ')'. If num '('s == num ')'s, maxLen = max(maxLen, 2*num '('s) else if num ')'s > num '('s, reset num '('s and ')'s. Do same iterating backward over string except check if num ')'s < num '('s.</b></br>
   https://github.com/mshenoy2481/interview_qs/blob/master/leetcode32.cpp</br>

- https://leetcode.com/problems/find-the-duplicate-number/</br>
  Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.</br>
  There is only one repeated number in nums, return this repeated number.</br>
  You must solve the problem without modifying the array nums and uses only constant extra space.</br>
  Example 1:</br>
  Input: nums = [1,3,4,2,2]</br>
  Output: 2</br>
  Example 2:</br>
  Input: nums = [3,1,3,4,2]</br>
  Output: 3</br>
  <b>Rabbit-hare linked list solution</b></br>
  https://github.com/mshenoy2481/interview_qs/blob/master/leetcode287.cpp</br>
  


