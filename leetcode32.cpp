#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

int longestValidParentheses(std::string s) {
    std::stack<int> indStack;
    indStack.emplace(-1);
    int maxLen = 0;
    for(int i = 0;  i < s.length();     i++)
    {
        if(s[i] == '(')
        {
            indStack.emplace(i);
        }
        else
        {
            if(indStack.top() >= 0 && s[indStack.top()] == '(')
            {
                indStack.pop();
                maxLen = std::max(maxLen, i-(indStack.top()));
            }
            else
            {
                indStack.emplace(i);
            }
        }
    }
    return maxLen;
}

int longestValidParentheses1n(std::string s) {
    int l = 0;
    int r = 0;
    int maxLen = 0;
    for(int i = 0;  i < s.length();     i++)
    {
        if(s[i] == '(')
        {
            l++;
        }
        else
        {
            r++;
        }
        if(l == r)
        {
            maxLen = std::max(maxLen, l+r);
        }
        else if(l < r)
        {
            l = r = 0;
        }
    }
    l = r = 0;
    for(int i = s.length()-1;  i >= 0;     i--)
    {
        if(s[i] == '(')
        {
            l++;
        }
        else
        {
            r++;
        }
        if(l == r)
        {
           maxLen = std::max(maxLen, l+r);
        }
        else if(l > r)
        {
            l = r = 0;
        }
    }
    return maxLen;
}

int main()
{
    std::string s = "(()";
    std::cout << s << "   " << longestValidParentheses1n(s) << std::endl;
    s = ")()())";
    std::cout << s << "   " << longestValidParentheses1n(s) << std::endl;
    s = "";
    std::cout << s << "   " << longestValidParentheses1n(s) << std::endl;
}

