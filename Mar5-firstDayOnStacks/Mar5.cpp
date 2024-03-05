#include <iostream>

#include<stack>
#include <vector>

using namespace std;

string reverseAString(stack<char> inputStack)
{
    while (!inputStack.empty())
    {
        //char currentChar = inputStack.top(); 

        //string reversedString = reversedString + currentChar; 

        cout << inputStack.top();
        inputStack.pop(); 
        //INTEWNTIONAL error!
    }
    cout << "\n";

    return ""; 
}

int main()
{
    stack<char> charStack; 
    //charStack.at()
    //charStack[3] 
    charStack.push('r');
    charStack.push('a');
    charStack.push('c');
    charStack.push('e');
    charStack.push('c');
    charStack.push('a');

    //for (int i = inputString.length(); i > 0; i--)
    //std::reverse()

    reverseAString(charStack);

    //cout << sizeof(main()) << endl; 
    //main(); 
    
    //while (true)
    //{

    //}




    return 0;
}