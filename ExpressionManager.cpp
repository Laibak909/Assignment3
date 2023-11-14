// ExpressionManager.cpp

#include "ExpressionManager.h"

bool ExpressionManager::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

bool ExpressionManager::parenthesesMatch(char open, char close) {
    return ((open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']'));
}

bool ExpressionManager::balancedParenthesesCheck(const std::string& expression) {
    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            charStack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (charStack.empty() || !parenthesesMatch(charStack.top(), c)) {
                return false; // Unmatched parentheses
            }
            charStack.pop();
        }
    }

    return charStack.empty(); // Expression is balanced if the stack is empty
}

std::string ExpressionManager::infixToPostfix(const std::string& infix) {
    std::string postfix = "";
    std::stack<char> opStack;

    // Define operator precedence
    std::unordered_map<char, int> precedence{
        {'+', 1}, {'-', 1},
        {'*', 2}, {'/', 2}, {'%', 2}
    };

    for (char c : infix) {
        if (isOperator(c)) {
            while (!opStack.empty() && precedence[opStack.top()] >= precedence[c]) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
        else if (c == '(') {
            opStack.push(c);
        }
        else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // Pop '('
        }
        else {
            postfix += c; // Operand, add to the postfix expression
        }
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}


int main() {
    ExpressionManager expressionManager;
    std::string infixExpression;

    // Read infix expression from the user
    std::cout << std::endl;
    std::cout << "  Enter an infix expression: ";
    std::getline(std::cin, infixExpression);

    // Perform Balanced Parentheses Check
    if (expressionManager.balancedParenthesesCheck(infixExpression)) {
        // If balanced, convert infix to postfix and display
        std::cout << std::endl;
        std::string postfixExpression = expressionManager.infixToPostfix(infixExpression);
        std::cout << "  Postfix expression: " << postfixExpression << std::endl;
    }
    else {
        std::cout << "Invalid expression. Unbalanced parentheses." << std::endl;
    }

    return 0;
}

