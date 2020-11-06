
#ifndef __TEST_LINKED_H__
#define __TEST_LINKED_H__

#include <iostream>
#include <string>

#include "linked.h"

template <class T>
class TestLinked {
    public:
        void test_append_data(Linked<T>&, T);
        bool test_contain_data(Linked<T>&, T);
        void test_remove_data(Linked<T>&, T);

    private:
        void error(std::string);
};

/**
 *  錯誤訊息函式。
 *
 *  @param  string: 要印出的錯誤訊息
 *  @return none.
 **/
template <class T>
void TestLinked<T>::error(const std::string err) {
    std::cout << "ERROR!" << std::endl;
    std::cout << "  ==> " << err << std::endl;

    exit(-1);
}

/**
 *  測試函式。測試 append_data()。
 *
 *  @param  none.
 *  @return none.
 **/
template <class T>
void TestLinked<T>::test_append_data(Linked<T>& linked, T data) {
    std::cout
        << "Testing function: append_data()..."
        << std::endl;

    linked.dump_list();

    std::cout
        << "    Append node with node.data == "
        << data << std::endl;

    linked.append_data(data);

    linked.dump_list();
} // test_append_data()

/**
 *  測試函式。測試 contain_data()。
 *
 *  @param  none.
 *  @return none.
 **/
template <class T>
bool TestLinked<T>::test_contain_data(Linked<T>& linked, T data) {
    bool found = false;

    std::cout
        << "Testing function: contain_data()..."
        << std::endl;

    std::cout
        << "    First, append some node with node.data == "
        << data <<  " for testing." << std::endl;

    linked.append_data(data);

    linked.dump_list();

    if (linked.contain_data(data)) {
        found = true;

        std::cout
            << "    Contain node with node.data == "
            << data << std::endl;
    }
    else {
        error("contain_data() failed!!!");
    };

    return found;
} // test_contain_data()

/**
 *  測試函式。測試 remove_data()。
 *
 *  @param  none.
 *  @return none.
 **/
template <class T>
void TestLinked<T>::test_remove_data(Linked<T>& linked, T data) {
    std::cout
        << "Testing function: remove_data()..."
        << std::endl;

    std::cout
        << "    First, append a node with node.data == "
        << data <<  " for testing." << std::endl;

    linked.append_data(data);

    linked.dump_list();

    std::cout
        << "    Delete node with node.data == "
        << data << std::endl;

    linked.remove_data(data);

    linked.dump_list();
} // test_remove_data()

#endif

// test_linked.h
