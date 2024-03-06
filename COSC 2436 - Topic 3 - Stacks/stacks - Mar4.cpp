#include <iostream>

#include<vector>

#include<stack>

using namespace std;

void printStack(std::stack<char> charStack) //pass by value (versus pass by ref) 
{
    while (!charStack.empty())
    {
        cout << charStack.top();
        charStack.pop(); //removes the top element off of the stack 
    }
}



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
}


int main()
{
    //stack<int> numsStack; 
    //cout << numsStack.top(); //AKA: "peek" in other languages 
    

    string balanced = R"({})";

    cout << std::boolalpha; 
    cout << "Is it balanced?: " << isBalanced(balanced) << endl;


 /*   std::stack<char> palindromeStack;
    palindromeStack.push('h');
    palindromeStack.push('a');
    palindromeStack.push('n');
    palindromeStack.push('n');
    palindromeStack.push('a');
    palindromeStack.push('h');
    palindromeStack.push('z');

    cout << "\n" << palindromeStack.size() << endl;

    printStack(palindromeStack);

    cout << palindromeStack.size() << endl; */

    //cout << palindromeStack.at(2) << endl;
    //for (auto& element : palindromeStack)
    //{
    //    cout << element << endl; 
    //}
    //vector<int> v1; 
    

    
    //main(); //infinite recursion (causes stack overflow) 
                //see Linker -> System settings for default 1 MB value

    return 0;
}