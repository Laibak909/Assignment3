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

