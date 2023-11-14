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
