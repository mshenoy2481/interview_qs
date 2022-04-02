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

- https://leetcode.com/problems/longest-palindromic-substring/</br>
  <b>Check for the longest palindrome at every index using the "blooming" technique. The largest of these is the answer.</b></br>
  https://github.com/mshenoy2481/interview_qs/blob/master/leetcode5.cpp</br>

- https://leetcode.com/problems/longest-common-subsequence/</br>
  <b>Classic DP problem. Iterate over both strings. For every index combo(i,j), if the the chars is both strings are same, increment size of the subsequence, else subsequence size = max(subsequence(i+1, j), subsequenc(i, j+1))</br>
     for(int i = text1.length()-1;  i >= 0;      i--)  {</br>
        for(int j = text2.length()-1;   j >= 0;     j--) {</br>
                if(text1[i] == text2[j]) {</br>
                    dp[i][j] = 1 + dp[i+1][j+1];</br>
                } else {</br>
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);</br>
                }</br>
            }</br>
        }</br></b>
  https://github.com/mshenoy2481/interview_qs/blob/master/leetcode1143.cpp</br>

- https://leetcode.com/problems/longest-palindromic-subsequence/</br>
  <b>Same problem as ablove (longest common subsequence). Inputs are string and reverse string.</b></br>
  https://github.com/mshenoy2481/interview_qs/blob/master/leetcode1143.cpp</br>

- https://leetcode.com/problems/valid-palindrome-iii/</br>
  <b>Find the length of the longest palindrome subsequence using longest common subsequence technique. Answer is (size of the string - this length) >= k.</b></br>
  https://github.com/mshenoy2481/interview_qs/blob/master/leetcode1216.cpp</br>
  
- https://leetcode.com/problems/paint-house-ii/</br>
  <b>Two ways to solve this:</br> 
     1. DP+backtracking - Top down recursion. For every recursion, iterate over all colors. For every color index, mark the color index for the next house as -1 and calculate the minimum cost. Backtrack on the color index.</br>
       if(ind < costs.size()-1) {</br>
           temp = costs[ind+1][i];</br>
           costs[ind+1][i] = -1;</br>
       }</br>
       dp[ind][i] = costs[ind][i] + tryNextCost(costs, ind+1, dp);</br>
       if(ind < costs.size()-1)  {</br>
           costs[ind+1][i] = temp;</br>
       }</br>
     2. Simple DP. At every iteration, find the minimum and second minimum value and use those values in the next iteration.</br>
        -----</br>
        for(int j = 0;  j < costs[i].size();    j++)  {</br>
            int currVal = costs[i][j];</br>
            if(prevMinInd != -1 && j != prevMinInd)  {</br>
                currVal += prevMin;</br>
            } else if(prevMin2Ind != -1)  {</br>
                currVal += prevMin2;</br>
            }</br>
        ------</b></br>
    https://github.com/mshenoy2481/interview_qs/blob/master/leetcode265.cpp</br>

- https://leetcode.com/problems/minimize-max-distance-to-gas-station/</br>
  <b>Two ways to do this:</br>
     1. Heap: Throw all the differences between consecutive stations and number of gas stations in between (starting with 0) on the priority_queue. priotrity_queue ordered by (distance/number of stations in between) While k > 0, pop the next (distance, station nums) off the front of the priority_queue, decrement k, increment the station nums in the popped element and push the popped element back on the queue.</br>
     2. Binary search: Search space is 1e-6 to largest distance between consecutive stations. In this search space, search for the minimum max distance such that k gas stations can be placed in between. To do this, find the mid and find the number of stations that can be placed for this mid (iterate over the station array, divide the distance between consective distances by the mid to find the number of stations that can be placed in between and add to the total). If these total number of stations > k, mid is too small as the max distance and search space is [mid+1e-6, r] else search space is [l, mid].</br>
    https://github.com/mshenoy2481/interview_qs/blob/master/leetcode774.cpp</br>
   


