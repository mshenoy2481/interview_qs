#include <iostream>

std::string longestPalindrome(std::string s) {
    int maxLen = 0;
    int maxL = -1;
    for(int i = 0;  i < s.length(); i++)
    {
        int l = i;
        int r = i;
        while(l >= 0 && r < s.length() && s[l] == s[r])
        {
            l--;
            r++;
        }
        l++;
        r--;
        if(maxLen < r-l+1)
        {
            maxLen = r-l+1;
            maxL = l;
        }
        if(i > 0 && s[i-1] == s[i])
        {
            l = i-1;
            r = i;
            while(l >= 0 && r < s.length() && s[l] == s[r])
            {
                l--;
                r++;
            }
            l++;
            r--;
            if(maxLen < r-l+1)
            {
                maxLen = r-l+1;
                maxL = l;
            }
        }
    }
    return s.substr(maxL, maxLen);
}

int main()
{
    std::cout << longestPalindrome("babad") << std::endl;
    std::cout << longestPalindrome("cbbd") << std::endl;
    std::cout << longestPalindrome("aacabdkacaa") << std::endl;
}
