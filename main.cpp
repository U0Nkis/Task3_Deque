#include <iostream>
#include "Deque.h"
using namespace std;

int main() {
    Deque<int> intDeque;
    intDeque.push_front(1);
    intDeque.push_back(2);
    intDeque.push_back(3);
    intDeque.print();
    intDeque.pop_back();
    intDeque.print();

    Deque<string> stringDeque;
    stringDeque.push_front("middle");
    stringDeque.push_front("left");
    stringDeque.push_back("right");
    stringDeque.print();
    stringDeque.pop_front();
    stringDeque.print();

    return 0;
}