
#include <iostream>

#include "linked.h"

/**
 *  生成指定長度的 Linked List。節點內容預設為由 0 開始的流水號。
 *
 *  @param  int:    要生成的 Linked List 的長度
 *  @return Node *: 指向生成的 Linked List 第一個節點的指標
 **/
Linked::Linked(int len) {
    head = new Node();

    Node *node = head;

    for (int i = 0; i < len; i ++) {
        node->next = new Node();

        node = node->next;

        node->data = i;
        node->next = nullptr;
    }
} // List::List()

/**
 *  釋放 Linked List，
 *
 *  @param  Node *: 指向要釋放的 Linked List 的指標
 *  @return none.
 **/
Linked::~Linked() {
    while (head->next != nullptr) {
        Node *dummy = head;

        head = head->next;
        delete dummy;    // 釋放記憶體
    }

    delete head; // 釋放最後一個節點
} // List::~List()
/**
 *  在 Linked List 最後面，增加一個節點。
 *
 *  @param  Node *: 指向 Linked List 第一個節點的指標
 *  @param  int:    要新增的節點資料值
 *  @return none.
 *  @return none.
 **/
void Linked::append_data(int data) {
    // put your code here.
} // Linked::append_data()

/**
 *  在 Linked List 最後面，增加一個節點。
 *
 *  @param  Node *: 指向 Linked List 第一個節點的指標
 *  @param  int:    要搜尋的節點資料值
 *  @return bool:   true  資料存在 Linked List 內
 *                  false 資料 '不' 存在 Linked List 內
 **/
bool Linked::contain_data(int data) {
    Node *node = head;
    bool found = false;

    while (node->next != nullptr) {
        node = node->next;

        if (node->data == data) {
            found = true;

            break;
        }
    }

    return found;
} // Linked::contain_data()

/**
 *  在 Linked List 最後面，*移除* 擁有特定值的 *第一個* 節點。
 *
 *  @param  Node *: 指向 Linked List 第一個節點的指標
 *  @param  int:    要移除的節點資料值
 *  @return none.
 **/
void Linked::remove_data(int data) {
    // put your code here.
} // Linked::remove_data()

/**
 *  將 Linked List 內容 *傾印* (dump) 在螢幕上。
 *
 *  @param  Node *: 指向 Linked List 第一個節點的指標
 *  @return none.
 **/
void Linked::dump_list() {
    std::cout << "  Linked List:" << std::endl;
    std::cout << "    ";

    Node *node = head;

    while (node->next != nullptr) {
        node = node->next;

        std::cout << "[" << node->data << "] -> ";
    }

    std::cout << "$" << std::endl;
} // Linked::dump_list()

// linked.cpp
