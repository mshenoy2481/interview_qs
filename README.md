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
    <b>Map of prefix-sum vs index of prefix sum. As map is created, check if currPrefixSum-k can be found in the map, maxLen = max(maxLen, i-map[currPrefixSum-k]+1. Also, make sure to add 0->-1 in the map.</b>

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
  <b>Sliding window. Calculate the number of 1s in the array - thats the window size. Aim is to get all 1's in the window and minimize the slips needed for that. Move that window from start to end keeping track of the 0s to flip at every start index. Minimum of those flips is the answer.</b>
  
  - 

