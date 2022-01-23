/**
Given a chest board that is only 1 row, and only filled with pawns that can move step forward in their direction. Return
True or False if the "new board" given is a valid possible play
white ---->
<----
black

Example:
Input ->
    original : ["white", "_", "_", "black"]
    new board:  ["_", "white", "black", "_"] -> Valid  - True
    new board:  ["_", "black", "white",  "_"] -> Invalid - False

Output ->
    True

is_valid_chest_move(["white", None, None, "black"], [None, "white", "black", None]): -> True
**/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

bool isValidMove(std::vector<std::string>& originalBoard, std::vector<std::string>& targetBoard)
{
    int whitesFound = 0;
    for(int i = 0;  i < originalBoard.size();   i++)
    {
        if(originalBoard[i] == "white")
        {
            whitesFound++;
        }
        else if(originalBoard[i] == "black" || targetBoard[i] == "black")
        {
            whitesFound = 0;
        }
        if(targetBoard[i] == "white")
        {
            if(whitesFound == 0)
            {
                return false;
            }
            whitesFound--;
        }
    }
    int blacksFound = 0;
    for(int i = originalBoard.size()-1;     i >= 0;     i--)
    {
        if(originalBoard[i] == "black")
        {
            blacksFound++;
        }
        else if(originalBoard[i] == "white" || targetBoard[i] == "white")
        {
            blacksFound = 0;
        }
        if(targetBoard[i] == "black")
        {
            if(blacksFound == 0)
            {
                return false;
            }
            blacksFound--;
        }
    }
    return true;
}


int main(int argc, const char** argv)
{
    std::ifstream testFile("chessmovestest");
    std::string nextLine = "";
    std::cout << std::boolalpha;
    while(std::getline(testFile, nextLine))
    {
        if(nextLine.back() == '\r')
        {
            nextLine.erase(nextLine.size()-1);
        }
        std::stringstream sstr(nextLine);
        std::cout << "Original: [" << nextLine << "] " << std::endl;
        std::vector<std::string> originalVec;
        std::string nextToken;
        while(std::getline(sstr, nextToken, ','))
        {
            originalVec.emplace_back(nextToken);
        }
        nextLine.clear();
        std::getline(testFile, nextLine);
        if(nextLine.back() == '\r')
        {
            nextLine.erase(nextLine.size()-1);
        }
        std::cout << "Target: [" << nextLine << "] "  << std::endl;
        sstr.clear();
        sstr.str(nextLine);
        std::vector<std::string> targetVec;
        nextToken.clear();
        while(std::getline(sstr, nextToken, ','))
        {
            targetVec.emplace_back(nextToken);
        }
        std::cout << "   Is Valid: " << isValidMove(originalVec, targetVec) << std::endl;
        std::cout.clear();
    }
}
