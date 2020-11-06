
#include "linked.h"
#include "test_linked.h"

/**
 *  Linked list 測試函式。測試 append_data, contain_data 和
 *  remove_data.
 *
 *  @param  len:    測試資料筆數
 *  @param  data:   存放測試資料的陣列
 *  @return none.
 **/
template<class T>
void test_list(int len, T data[]) {
    Linked<T> linked;
    TestLinked<T> test;

    for (int i = 0; i < len; i ++) {
        test.test_append_data(linked, data[i]);
    }

    for (int i = 0; i < len; i ++) {
        test.test_contain_data(linked, data[i]);
    }

    for (int i = 0; i < len; i ++) {
        test.test_remove_data(linked, data[i]);
    }
} // test_list()

int main(int argc, char *argv[]) {
    int int_data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::string str_data[] = {
        "this",
        "is",
        "a",
        "test",
    };

    test_list(sizeof(int_data)/sizeof(int_data[0]), int_data);
    test_list(sizeof(str_data)/sizeof(str_data[0]), str_data);
} // main()

// main.cpp
