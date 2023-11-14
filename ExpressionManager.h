// ExpressionManager.h

#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

class ExpressionManager {
private:
    std::stack<char> charStack;

    // Utility function to check if a character is an operator
    bool isOperator(char c);

    // Utility function to check if two parentheses types match
    bool parenthesesMatch(char open, char close);

public:
    // Function to perform Balanced Parentheses Check
    bool balancedParenthesesCheck(const std::string& expression);

    // Function to convert infix expression to postfix expression
    std::string infixToPostfix(const std::string& infix);
};

#endif // EXPRESSION_MANAGER_H
