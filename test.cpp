#include <iostream>
#include <string>
#include "deque.h"

using namespace std;

int passed = 0, failed = 0;

#define TEST(isPassed) do { \
    if (isPassed) ++passed; \
    else { ++failed; cout << "FAIL: " << #isPassed << endl; } \
} while (0)

void testIntDeque() {
    Deque<int> d;
    d.push_back(1);
    d.push_front(0);
    d.push_back(2);

    TEST(d.front() == 0);
    TEST(d.back() == 2);
    TEST(d.getSize() == 3);

    d.pop_front();
    TEST(d.front() == 1);
    d.pop_back();
    TEST(d.back() == 1);
    d.pop_back();
    TEST(d.empty());
}

void testStringDeque() {
    Deque<string> d;
    d.push_back("world");
    d.push_front("hello");

    TEST(d.front() == "hello");
    TEST(d.back() == "world");

    d.pop_front();
    TEST(d.front() == "world");
    TEST(d.getSize() == 1);
}

int main() {
    testIntDeque();
    testStringDeque();

    cout << "Passed: " << passed << ", Failed: " << failed << endl;
    return failed;
}