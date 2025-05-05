#ifndef DEQUE_H
#define DEQUE_H

template<typename T>
class Deque {
    T* data;
    int capacity;
    int frontIndex;
    int backIndex;
    int size;

    void resize(int newCapacity);

public:
    Deque();
    ~Deque();

    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void pop_front();
    T& front() const;
    T& back() const;
    bool empty() const;
    int getSize() const;
    T& operator[](int index) const;
    void print() const;
};

#include "Deque.cpp"

#endif
