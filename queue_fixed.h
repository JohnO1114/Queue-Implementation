#include <iostream>
#include <cassert>

template <typename T>
class Queue {
    T *data;
    int head;
    int tail;
    int maxsize;

public:
    Queue(int size) :head(0), tail(0), maxsize(size)  {
        data = new T[maxsize]; 
    }

    ~Queue() {
        delete[] data;
    }

    void push(const T &value) {
        data[tail] = value;
        tail = (tail + 1) % maxsize;
    }

    T pop() {
        T popped = data[head];
        head = (head + 1) % maxsize;
        return popped;
    }

    bool isEmpty() const {
        return head == tail;
    }

    int getSize() const {
        return (tail - head + maxsize) % maxsize;
    }
};