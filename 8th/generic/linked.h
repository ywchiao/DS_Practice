
#ifndef __LINKED_H__
#define __LINKED_H__

#include <iostream>

#include "node.h"

template <class T>
class Linked {
    public:
        Linked();
        ~Linked();

    public:
        void append_data(T);
        bool contain_data(T);
        void remove_data(T);

    public:
        void dump_list();

    private:
        Node<T> *head;
};

/**
 *   初始化 Linked List，先準備一個 head 指標。
 **/
template <class T>
Linked<T>::Linked() {
    head = new Node<T>();
} // List::List()

/**
 *  釋放 Linked List，
 **/
template <class T>
Linked<T>::~Linked() {
    while (head->next != nullptr) {
        Node<T> *dummy = head;

        head = head->next;
        delete dummy;    // 釋放記憶體
    }

    delete head; // 釋放最後一個節點
} // List::~List()

/**
 *  在 Linked List 最後面，增加一個節點。
 *
 *  @param  data:   放在新增節點的資料值
 *  @return none.
 **/
template <class T>
void Linked<T>::append_data(T data) {
    Node<T> *node = head;

    while (node->next != nullptr) {
        node = node->next;  // 找最後一個節點
    }

    node->next = new Node<T>();    // 新增一個節點到
                                // Linked List 尾端
    node->next->data = data;    // 設定 .data
    node->next->next = nullptr; // 設定 .next
} // Linked::append_data()

/**
 *  搜尋 Linked List 裡, 是否有特定值存在。
 *
 *  @param  data:   要搜尋的節點資料值
 *  @return bool:   true  資料存在 Linked List 內
 *                  false 資料 '不' 存在 Linked List 內
 **/
template <class T>
bool Linked<T>::contain_data(T data) {
    Node<T> *node = head;
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
 *  在 Linked List *移除* 擁有特定值的 *第一個* 節點。
 *
 *  @param  data:   要移除的節點資料值
 *  @return none.
 **/
template <class T>
void Linked<T>::remove_data(T data) {
    Node<T> *node = head;

    while (node->next != nullptr) {
        Node<T> *dummy = node->next;   // 候選節點

        if (dummy->data == data) {  // 找到了？
            node->next = dummy->next;
            delete dummy;   // 釋放記憶體

            break;
        }

        node = node->next;
    }
} // Linked::remove_data()

/**
 *  將 Linked List 內容 *傾印* (dump) 在螢幕上。
 *
 *  @param  none.
 *  @return none.
 **/
template <class T>
void Linked<T>::dump_list() {
    std::cout << "  Linked List:" << std::endl;
    std::cout << "    ";

    Node<T> *node = head;

    while (node->next != nullptr) {
        node = node->next;

        std::cout << "[" << node->data << "] -> ";
    }

    std::cout << "$" << std::endl;
} // Linked::dump_list()

#endif

// linked.h
