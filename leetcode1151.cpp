#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

int minSwaps(std::vector<int>& data) {
    int sum = std::accumulate(data.begin(), data.end(), 0);
    int onesSoFar = 0;
    int maxOnes = 0;
    int start = 0;
    for(int i = 0;  i < data.size();    i++)
    {
        onesSoFar += data[i];
        if(i >= sum)
        {
            onesSoFar -= data[start];
            start++;
        }
        maxOnes = std::max(maxOnes, onesSoFar);
    }
    return sum-maxOnes;
}

int main()
{
    std::vector<int> nums = {1,0,1,0,1};
    std::cout << minSwaps(nums) << std::endl;
    nums = {0,0,0,1,0};
    std::cout << minSwaps(nums) << std::endl;
    std::cout << minSwaps(nums) << std::endl;
    nums = {1,0,1,0,1,0,0,1,1,0,1};
    std::cout << minSwaps(nums) << std::endl;
}

