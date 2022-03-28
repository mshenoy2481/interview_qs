#include <vector>
#include <iostream>

bool searchBetween(std::vector<int>& nums, int target, int l, int r)
{
    if(l > r)
    {
        return false;
    }
    bool ret = false;
    int m = (l+r)/2;
    if(nums[m] == target)
    {
        return true;
    }
    else if(nums[l] <= target && target < nums[m])
    {
        return searchBetween(nums, target, l, m-1);
    }
    else if(nums[m] < target && target <= nums[r])
    {
        return searchBetween(nums, target, m+1, r);
    }
    else if(nums[m] > nums[r] && nums[m] < target)
    {
        return searchBetween(nums, target, m+1, r);
    }
    else if(nums[l] > nums[m] && nums[m] > target)
    {
        return searchBetween(nums, target, l, m-1);
    }
    else
    {
        return searchBetween(nums, target, l, m-1) ||
                        searchBetween(nums, target, m+1, r);
    }
}


bool search(std::vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size()-1;
    return searchBetween(nums, target, l, r);
}

int main()
{
    std::vector<int> v = {2,5,6,0,0,1,2};
    std::cout << std::boolalpha << search(v, 0) << std::endl;
    v = {2,5,6,0,0,1,2};
    std::cout << std::boolalpha << search(v, 3) << std::endl;
    v = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    std::cout << std::boolalpha << search(v, 2) << std::endl;
}
