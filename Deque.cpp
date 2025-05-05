#include <iostream>
#ifndef DEQUE_TPP
#define DEQUE_TPP

#include "Deque.h"

template<typename T>
Deque<T>::Deque() : capacity(10), frontIndex(0), backIndex(-1), size(0) {
    data = new T[capacity];
}

template<typename T>
Deque<T>::~Deque() {
    delete[] data;
}

template<typename T>
void Deque<T>::resize(int newCapacity) {
    T* newData = new T[newCapacity];
    int j = 0;
    for (int i = 0; i < size; ++i) {
        newData[j++] = (*this)[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
    frontIndex = 0;
    backIndex = size - 1;
}

template<typename T>
void Deque<T>::push_back(const T& value) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    backIndex = (backIndex + 1) % capacity;
    data[backIndex] = value;
    ++size;
}

template<typename T>
void Deque<T>::push_front(const T& value) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    frontIndex = (frontIndex - 1 + capacity) % capacity;
    data[frontIndex] = value;
    ++size;
}

template<typename T>
void Deque<T>::pop_back() {
    if (!empty()) {
        backIndex = (backIndex - 1 + capacity) % capacity;
        --size;
    }
}

template<typename T>
void Deque<T>::pop_front() {
    if (!empty()) {
        frontIndex = (frontIndex + 1) % capacity;
        --size;
    }
}

template<typename T>
T& Deque<T>::front() const {
    return data[frontIndex];
}

template<typename T>
T& Deque<T>::back() const {
    return data[backIndex];
}

template<typename T>
bool Deque<T>::empty() const {
    return size == 0;
}

template<typename T>
int Deque<T>::getSize() const {
    return size;
}

template<typename T>
T& Deque<T>::operator[](int index) const {
    return data[(frontIndex + index) % capacity];
}

template<typename T>
void Deque<T>::print() const {
    for (int i = 0; i < size; ++i) {
        std::cout << (*this)[i] << " ";
    }
    std::cout << std::endl;
}

#endif