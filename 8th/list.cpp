
#include <iostream>

#include "node.h"

/**
 *  在 Linked List 最後面，增加一個節點。
 *
 *  @param  node:   指向 Linked List 第一個節點的指標
 *  @param  data:   要新增的節點資料值
 *  @return none.
 **/
void append_data(Node *node, int data) {
    while (node->next != nullptr) {
        node = node->next;  // 找最後一個節點
    }

    node->next = new Node();    // 新增一個節點到
                                // Linked List 尾端
    node->next->data = data;    // 設定 .data
    node->next->next = nullptr; // 設定 .next
} // append_data()

/**
 *  搜尋 Linked List 裡, 是否有特定值存在。
 *
 *  @param  node:   指向 Linked List 第一個節點的指標
 *  @param  data:   要搜尋的節點資料值
 *  @return bool:   true  資料存在 Linked List 內
 *                  false 資料 '不' 存在 Linked List 內
 **/
bool contain_data(Node *node, int data) {
    bool found = false;

    while (node->next != nullptr) {
        node = node->next;

        if (node->data == data) {
            found = true;

            break;
        }
    }

    return found;
} // contain_data()

/**
 *  在 Linked List *移除* 擁有特定值的 *第一個* 節點。
 *
 *  @param  node:   指向 Linked List 第一個節點的指標
 *  @param  data:   要移除的節點資料值
 *  @return none.
 **/
void remove_data(Node *node, int data) {
    while (node->next != nullptr) {
        Node *dummy = node->next;   // 候選節點

        if (dummy->data == data) {  // 找到了？
            node->next = dummy->next;
            delete dummy;   // 釋放記憶體

            break;
        }

        node = node->next;
    }
} // remove_data()

/**
 *  將 Linked List 內容 *傾印* (dump) 在螢幕上。
 *
 *  @param  node:   指向 Linked List 第一個節點的指標
 *  @return none.
 **/
void dump_list(Node *node) {
    std::cout << "  Linked List:" << std::endl;
    std::cout << "    ";

    while (node->next != nullptr) {
        node = node->next;

        std::cout << "[" << node->data << "] -> ";
    }

    std::cout << "$" << std::endl;
} // dump_list()

/**
 *  釋放 Linked List，
 *
 *  @param  node:   指向要釋放的 Linked List 的指標
 *  @return none.
 **/
void free_list(Node *node) {
    while (node->next != nullptr) {
        Node *dummy = node;

        node = node->next;
        delete dummy;    // 釋放記憶體
    }

    delete node; // 釋放最後一個節點
} // free_list()

/**
 *  生成指定長度的 Linked List。節點內容預設為由 0 開始的流水號。
 *
 *  @param  len:    要生成的 Linked List 的長度
 *  @return Node *: 指向生成的 Linked List 第一個節點的指標
 **/
Node *new_list(int len) {
    Node *head = new Node();
    Node *node = head;

    for (int i = 0; i < len; i ++) {
        node->next = new Node();

        node = node->next;

        node->data = i;
        node->next = nullptr;
    }

    return head;
} // new_list()

/**
 *  錯誤訊息函式。
 *
 *  @param  err: 要印出的錯誤訊息
 *  @return none.
 **/
void error(std::string err) {
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
void test_append_data() {
    Node *head;

    std::cout
        << "Testing function: append_data()..."
        << std::endl;

    head = new_list(0);
    std::cout << std::hex << head->next << std::endl;
    dump_list(head);

    for (int i = 0; i < 10; i += 1) {
        std::cout
            << "    Append node with node.data == "
            << i << std::endl;

        append_data(head, i);
        dump_list(head);

        if (!contain_data(head, i)) {
            error("append_data() failed!!!");
        };
    }

    free_list(head);    // 釋放 Linked List
} // test_append_data()

/**
 *  測試函式。測試 contain_data()。
 *
 *  @param  none.
 *  @return none.
 **/
void test_contain_data() {
    Node *head;

    std::cout
        << "Testing function: contain_data()..."
        << std::endl;

    head = new_list(10);
    dump_list(head);

    for (int i = 0; i < 10; i += 1) {
        std::cout
            << "    Contain node with node.data == "
            << i << std::endl;

        if (!contain_data(head, i)) {
            error("contain_data() failed!!!");
        };
    }

    free_list(head);    // 釋放 Linked List
} // test_contain_data()

/**
 *  測試函式。測試 remove_data()。
 *
 *  @param  none.
 *  @return none.
 **/
void test_remove_data() {
    Node *head;

    std::cout
        << "Testing function: remove_data()..."
        << std::endl;

    head = new_list(10);
    dump_list(head);

    for (int i = 1; i < 10; i += 2) {
        std::cout
            << "    Delete node with node.data == "
            << i << std::endl;

        remove_data(head, i);
        dump_list(head);

        if (contain_data(head, i)) {
            error("remove_data() failed!!!");
        };
    }

    free_list(head);    // 釋放 Linked List
} // test_remove_data()

/**
 *  main()
 *
 *  @param  none.
 *  @return none.
 **/
int main(int argc, char *argv[]) {
    Node *head = new_list(10);

    dump_list(head);

//    test_append_data();
//    test_contain_data();
//    test_remove_data();
} // main()

// list.cpp
