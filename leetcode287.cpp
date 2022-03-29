#include <vector>
#include <iostream>

int findDuplicate(std::vector<int>& nums) {
    int slow = 0;
    int fast = 0;
    while(slow == 0 || slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    fast = 0;
    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main()
{
    std::vector<int> v = {1,3,4,2,2};
    std::cout << "Duplicate: " << findDuplicate(v) << std::endl;
    v = {3,1,3,4,2};
    std::cout << "Duplicate: " << findDuplicate(v) << std::endl;
    v = {2,2,2,2,2};
    std::cout << "Duplicate: " << findDuplicate(v) << std::endl;
}
