# interview_qs
Interview questions

- https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/</br>
  <b>Map of prefix-sum vs index of prefix sum. As map is created, check if currPrefixSum-k can be found in the map, maxLen = max(maxLen, i-map[currPrefixSum-k]+1. Also, make sure to add 0->-1 in the map.</b></br>
    https://github.com/mshenoy2481/interview_qs/blob/master/leetcode325.cpp</br>

- https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/</br>
  <b>Sliding window. Calculate the number of 1s in the array - thats the window size. Aim is to get all 1's in the window and minimize the slips needed for that. Move that window from start to end keeping track of the 0s to flip at every start index. Minimum of those flips is the answer.</b></br>
  https://github.com/mshenoy2481/interview_qs/blob/master/leetcode1151.cpp</br>

- https://leetcode.com/problems/search-in-rotated-sorted-array-ii/</br>
  <b>Binary search. There are 4 conditions where binary search is possible:</br>
       - nums[l] <= target && target < nums[m]</br>
       - nums[m] < target && target <= nums[r]</br>
       - nums[m] > nums[r] && nums[m] < target</br>
       - nums[l] > nums[m] && nums[m] > target</br>
    If any of these conditions are met, it is possible to reduce search space to half. If not, search on both sides.</b></br>
    https://github.com/mshenoy2481/interview_qs/blob/master/leetcode81.cpp</br>

- https://leetcode.com/problems/longest-valid-parentheses/</br>
  <b>Two ways:
    1. Using stack while iterating over the string. Push -1 on stack before iteration. If next char is (, push its index on the stack. If next char is ), if stack top points to (, pop from stack and maxLen is max(maxLen, i-stacktop), else push char index on stack.</br>
    2. Without stack - Iterating forward over the string, count '(' and ')'. If num '('s == num ')'s, maxLen = max(maxLen, 2*num '('s) else if num ')'s > num '('s, reset num '('s and ')'s. Do same iterating backward over string except check if num ')'s < num '('s.</b></br>
   https://github.com/mshenoy2481/interview_qs/blob/master/leetcode32.cpp</br>

- https://leetcode.com/problems/find-the-duplicate-number/</br>
  <b>Rabbit-hare linked list solution</b></br>
  https://github.com/mshenoy2481/interview_qs/blob/master/leetcode287.cpp</br>

- https://leetcode.com/problems/handshakes-that-dont-cross/</br>
  <b>DP bottom up:</br>
      for(int i = 1;  i <= numPeople/2;     i++)  {</br>
            for(int j = 1;  j <= i;     j++) {</br>
                dp[i] = dp[i] + dp[i-j]*dp[i-j];</br>
      }}</br></b>
      https://github.com/mshenoy2481/interview_qs/blob/master/leetcode1259.cpp</br>
  
- https://leetcode.com/problems/one-edit-distance/</br>
  <b>Simple two pointer O(n) solution<b></br>
  https://github.com/mshenoy2481/interview_qs/blob/master/leetcode161.cpp</br>

- https://leetcode.com/problems/edit-distance/</br>
  <b>DP solution. At every index combination, one of the following happens:</br>
     1.letters are the same, in which case number of operations are not incremented and both indices are incremented.</br>
     2.else, pick the minimum of the following: insert word2 letter, in which case word2 index increases, replace word1 letter by word2 letter in which case both indexes increment or delete word1 letter in which case word1 index increases. In all cases, number of operations are incremented by 1.</br>
    for(int ind1 = word1.length()-1;   ind1 >= 0;      ind1--){</br>
        for(int ind2 = word2.length()-1;   ind2 >= 0;      ind2--){</br>
            if(word1[ind1] == word2[ind2]){</br>
                dp[ind1][ind2] = dp[ind1+1][ind2+1];</br>
            } else {</br>
                dp[ind1][ind2] = min(dp[ind1+1][ind2+1], dp[ind1+1][ind2], dp[ind1][ind2+1]);</br>
                dp[ind1][ind2]++;</br>
            } } }</br></b>
    https://github.com/mshenoy2481/interview_qs/blob/master/leetcode72.cpp</br>



