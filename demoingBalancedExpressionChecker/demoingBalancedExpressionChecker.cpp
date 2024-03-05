#include <iostream>

#include<stack>

using namespace std;

bool isMatch(char openSymbol, char closeSymbol)
{
    if (openSymbol == '(' && closeSymbol == ')')
    {
        return true;
    }
    else if (openSymbol == '{' && closeSymbol == '}')
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool isBalanced(string inputString)
{
    std::stack<char> openSymbolStack;
    for (auto& currentChar : inputString) {
        //check if current char is opening symbol
        if (currentChar == '(' || currentChar == '{') {
            openSymbolStack.push(currentChar);
        }

        //check for closing symbol:
        else if (currentChar == ')' || currentChar == '}') {
            if (openSymbolStack.empty())
            {
                return false; //close symbol MUST be preceded by an open symbol
            }
            if (isMatch(openSymbolStack.top(), currentChar))
            {
                openSymbolStack.pop();
            }
            else { //isMatch returned false, so string is unbalanced
                return false;
            }
        }// add else (neither an open symbol nor a close symbol)
    } //end for loop

    if (!openSymbolStack.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
} //end `isBalanced`


int main()
{


    string balancedString = "(() { () { } })";

    cout << std::boolalpha; 
    cout << "is `balancedString` indeed balanced? " << isBalanced(balancedString) << endl;

    string unbalancedString = "( ) { ( ) { } } }";
    cout << "how about the UNBALANCED one? " << isBalanced(unbalancedString) << endl;

    return 0;
}