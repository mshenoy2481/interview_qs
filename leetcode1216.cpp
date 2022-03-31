#include <iostream>
#include <vector>
#include <algorithm>

bool isValidPalindrome(std::string s, int k) {
    std::string t(s.rbegin(), s.rend());
    std::vector<int> dp(s.length()+1,  0);
    std::vector<int> nextDp(s.length()+1, 0);
    for(int i = s.length()-1;  i >= 0;     i--)
    {
        for(int j = t.length()-1;  j >= 0;     j--)
        {
            if(s[i] == t[j])
            {
                dp[j] = 1 + nextDp[j+1];
            }
            else
            {
                dp[j] = std::max(nextDp[j], dp[j+1]);
            }
        }
        nextDp = dp;
    }
    return (s.length() - dp[0]) <= k;
}

int main()
{
    std::cout << std::boolalpha << isValidPalindrome("abcdeca", 2) << std::endl;
    std::cout << std::boolalpha << isValidPalindrome("abbababa", 1) << std::endl;
}
