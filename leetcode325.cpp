#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

int maxSubArrayLen(std::vector<int>& nums, int k) {
    std::unordered_map<int,int> prefixSums;
    int pref = 0;
    int maxLen = 0;
    for(int i = 0;  i < nums.size();    i++)
    {
        pref += nums[i];
        if(pref == k)
        {
            maxLen = std::max(maxLen, i+1);
        }
        else
        {
            auto itr = prefixSums.find(pref-k);
            if(itr != prefixSums.end())
            {
                maxLen = std::max(maxLen, i-itr->second);
            }
        }
        prefixSums.emplace(pref, i);
    }
    return maxLen;
}

int main()
{
    std::vector<int> nums = {1,-1,5,-2,3};
    std::cout << maxSubArrayLen(nums, 3) << std::endl;
    nums = {1,-1,5,-2,3};
    std::cout << maxSubArrayLen(nums, 3) << std::endl;
}

