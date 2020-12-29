
#include <iostream>

#include "stack.h"
#include "test_stack.h"

int main() {
    TestStack<int> test_stack;

    for (int i = 0; i < 10; i ++) {
        test_stack.test_push_pop(i);
    }

    test_stack.test_empty();
} // main()
