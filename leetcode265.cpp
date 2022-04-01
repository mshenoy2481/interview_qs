#include <iostream>
#include <vector>
#include <limits>

int tryNextCost(std::vector<std::vector<int>>& costs, int ind, std::vector<std::vector<int>>& dp)
{
    if(ind == costs.size())
    {
        return 0;
    }
    int minCost = std::numeric_limits<int>::max();
    for(int i = 0;  i < costs[ind].size();  i++)
    {
        if(costs[ind][i] != -1)
        {
            if(dp[ind][i] == -1)
            {
                int temp = -1;
                if(ind < costs.size()-1)
                {
                    temp = costs[ind+1][i];
                    costs[ind+1][i] = -1;
                }
                dp[ind][i] = costs[ind][i] + tryNextCost(costs, ind+1, dp);
                if(ind < costs.size()-1)
                {
                    costs[ind+1][i] = temp;
                }
            }
            minCost = min(minCost, dp[ind][i]);
        }
    }
    return minCost;
}

int minCostII(std::vector<std::vector<int>>& costs) {
    int prevMinInd = -1, prevMin2Ind = -1;
    int prevMin = std::numeric_limits<int>::max(),
        prevMin2 = std::numeric_limits<int>::max();
    for(int i = costs.size()-1;     i >= 0;     i--)
    {
        int currMinInd = -1, currMin2Ind = -1;
        int currMin = std::numeric_limits<int>::max(),
            currMin2 = std::numeric_limits<int>::max();
        for(int j = 0;  j < costs[i].size();    j++)
        {
            int currVal = costs[i][j];
            if(prevMinInd != -1 && j != prevMinInd)
            {
                currVal += prevMin;
            }
            else if(prevMin2Ind != -1)
            {
                currVal += prevMin2;
            }

            if(currMinInd == -1 || currVal < currMin)
            {
                currMin2Ind = currMinInd;
                currMin2 = currMin;
                currMinInd = j;
                currMin = currVal;
            }
            else if(currMin2Ind == -1 || currVal < currMin2)
            {
                currMin2Ind = j;
                currMin2 = currVal;
            }
        }
        prevMinInd = currMinInd;
        prevMin = currMin;
        prevMin2Ind = currMin2Ind;
        prevMin2 = currMin2;
    }
    //return tryNextCost(costs, 0, dp);
    return prevMin;
}

int main()
{
    std::vector<std::vector<int>> input{{1,5,3},{2,9,4}};
    std::cout << minCostII(input) << std::endl;
    input = {{1,3},{2,4}};
    std::cout << minCostII(input) << std::endl;
}
