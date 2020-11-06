
#include <iostream>

#include "linked.h"

#include "test_linked.h"

/**
 *  錯誤訊息函式。
 *
 *  @param  string: 要印出的錯誤訊息
 *  @return none.
 **/
void TestLinked::error(const std::string err) {
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
void TestLinked::test_append_data() {
    Linked linked{0};

    std::cout
        << "Testing function: append_data()..."
        << std::endl;

    linked.dump_list();

    for (int i = 0; i < 10; i += 1) {
        std::cout
            << "    Append node with node.data == "
            << i << std::endl;

        linked.append_data(i);
        linked.dump_list();

        if (!linked.contain_data(i)) {
            error("append_data() failed!!!");
        };
    }
} // test_append_data()

/**
 *  測試函式。測試 contain_data()。
 *
 *  @param  none.
 *  @return none.
 **/
void TestLinked::test_contain_data() {
    Linked linked{10};

    std::cout
        << "Testing function: contain_data()..."
        << std::endl;

    linked.dump_list();

    for (int i = 0; i < 10; i += 1) {
        std::cout
            << "    Contain node with node.data == "
            << i << std::endl;

        if (!linked.contain_data(i)) {
            error("contain_data() failed!!!");
        };
    }
} // test_contain_data()

/**
 *  測試函式。測試 remove_data()。
 *
 *  @param  none.
 *  @return none.
 **/
void TestLinked::test_remove_data() {
    Linked linked{10};

    std::cout
        << "Testing function: remove_data()..."
        << std::endl;

    linked.dump_list();

    for (int i = 1; i < 10; i += 2) {
        std::cout
            << "    Delete node with node.data == "
            << i << std::endl;

        linked.remove_data(i);
        linked.dump_list();

        if (linked.contain_data(i)) {
            error("remove_data() failed!!!");
        };
    }
} // test_remove_data()

// test_linked.cpp
