# Assignment3- Part1
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

// Main.cpp

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

#Output

![Screenshot (12)](https://github.com/Laibak909/Assignment3/assets/113943791/1781cf62-cfe2-4d2c-b566-c9b1cdf48dff)




#Assignment3 -Part 2
// MyQueue.h

#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <queue>

class MyQueue {
private:
    std::queue<int> q;

public:
    // Inserts a new element at the rear of the queue.
    void enqueue(int element);

    // Removes the front element of the queue and returns it.
    int dequeue();

    // Returns the front element present in the queue without removing it.
    int front();

    // Checks if the queue is empty.
    bool isEmpty();

    // Returns the total number of elements present in the queue.
    size_t size();
};

#endif // MYQUEUE_H

// MyQueue.cpp

#include "MyQueue.h"

void MyQueue::enqueue(int element) {
    q.push(element);
}

int MyQueue::dequeue() {
    if (!q.empty()) {
        int frontElement = q.front();
        q.pop();
        return frontElement;
    }
    else {
        std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
        return -1; // Assuming -1 as an invalid value; you can customize it based on your needs.
    }
}

int MyQueue::front() {
    if (!q.empty()) {
        return q.front();
    }
    else {
        std::cerr << "Queue is empty. No front element." << std::endl;
        return -1; // Assuming -1 as an invalid value; you can customize it based on your needs.
    }
}

bool MyQueue::isEmpty() {
    return q.empty();
}

size_t MyQueue::size() {
    return q.size();
}


// Main.cpp


int main() {
    MyQueue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << std::endl;
    std::cout << "Front element: " << myQueue.front() << std::endl;

    std::cout << std::endl;
    std::cout << "Dequeue: " << myQueue.dequeue() << std::endl;

    std::cout << std::endl;
    std::cout << "Front element: " << myQueue.front() << std::endl;

    std::cout << std::endl;
    std::cout << "Is empty? " << (myQueue.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << std::endl;
    std::cout << "Queue size: " << myQueue.size() << std::endl;

    return 0;
}

#Output


![Screenshot (10)](https://github.com/Laibak909/Assignment3/assets/113943791/b3f83ef2-2644-46f5-a716-124ba3b3ffa3)



