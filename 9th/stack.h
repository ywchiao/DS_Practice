
#ifndef __STACK_H__
#define __STACK_H__

#define CAPACITY        128

template<class T>
class Stack {
public:
    void push(T);
    T pop();

public:
    inline void empty() { top_ = 0; };
    inline bool isEmpty() { return top_ == 0; };

public:
    T top();
    T peep(int);

private:
    int top_ = 0;
    T cache_[CAPACITY];
};

template<class T>
void Stack<T>::push(T e) {
    if (top_ == CAPACITY) {
        std::cout << "Error:" << std::endl;
        std::cout <<
            "  Stack is full. [" <<
            e <<
            "] is not pushed." <<
            std::endl;

        exit(-1);
    }

    cache_[top_] = e;
    top_ ++;
} // push()

template<class T>
T Stack<T>::pop() {
    if (top_ == 0) {
        std::cout << "Error:" << std::endl;
        std::cout <<
            "  Stack is empty." <<
            "Nothing to pop." <<
            std::endl;
        exit (-1);
    }

    top_ --;

    return cache_[top_];
} // pop()

template<class T>
T Stack<T>::top() {
    if (isEmpty()) {
        std::cout << "Error:" << std::endl;
        std::cout <<
            "  Stack is empty." <<
            std::endl;

        return NULL;
    }

    return cache_[top_];
} // top()

template<class T>
T Stack<T>::peep(int i) {
    if (i >= top_) {
        std::cout << "Error:" << std::endl;
        std::cout <<
            "  Out of range." <<
            std::endl;

        return NULL;
    }

    return cache_[top_ - (i + 1)];
} // peep()
#endif

// stack.h
