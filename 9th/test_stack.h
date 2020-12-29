
#ifndef __TEST_STACK_H__
#define __TEST_STACK_H__

#include <iostream>

#include "stack.h"

template<class T>
class TestStack {
public:
    bool test_push_pop(T);
    bool test_empty();

private:
    Stack<T> stack_;
};

template<class T>
bool TestStack<T>::test_push_pop(T e) {
    T t;

    std::cout << "Push [" << e << "] onto stack." << std::endl;
    stack_.push(e);

    t = stack_.pop();
    std::cout << "Pop [" << t << "] from stack." << std::endl;

    return  (e == t);
} // test_push_pop()

template<class T>
bool TestStack<T>::test_empty() {
    std::cout << "Try to empty stack..." << std::endl;
    stack_.empty();

    if (stack_.isEmpty()) {
        std::cout << "Empty succeed!" << std::endl;
    }
    else {
        std::cout << "Whoop! Failed!!" << std::endl;
    }

    return stack_.isEmpty();
} // test_empty()
#endif

// test_stack.h

