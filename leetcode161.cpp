#include <string>
#include <iostream>
#include <cstdlib>

bool isOneEditDistance(std::string s, std::string t) {
    if(std::abs(static_cast<int>(s.length()) - static_cast<int>(t.length())) > 1)
    {
        return false;
    }
    int sI = 0;
    int tI = 0;
    int diffs = 0;
    while(sI < s.length() && tI < t.length())
    {
        if(s[sI] == t[tI])
        {
            sI++;
            tI++;
        }
        else
        {
            diffs++;
            if(diffs > 1)
            {
                return false;
            }
            if(s.length() > t.length())
            {
                sI++;
            }
            else if(s.length() < t.length())
            {
                tI++;
            }
            else
            {
                sI++;
                tI++;
            }
        }
    }
    return ((diffs == 1 && sI == s.length() && tI == t.length()) ||
                (diffs == 0 && (sI != s.length() || tI != t.length())));
}


int main()
{
    std::cout << std::boolalpha << isOneEditDistance("ab", "acb") << std::endl;
    std::cout << std::boolalpha << isOneEditDistance("ab", "ab") << std::endl;
}
