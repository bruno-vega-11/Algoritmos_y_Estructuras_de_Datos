//
// Created by Usuario on 8/09/2025.
//

#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T val;
    Node* next;
    Node* prev;
    explicit Node(int _val):val(_val),next(nullptr),prev(nullptr){};
};

template<typename T>
class CDLinkedList {
private:
    Node<T>*head = nullptr;
public:
    CDLinkedList():head(nullptr){};
    ~CDLinkedList(){};

    T front() {
        return head->val;
    }

    T back() {
        return head->val;
    }

    void push_front(T value) {
        auto new_node = new Node<T>(value);
        if (head == nullptr) {
            new_node->next = head;
            new_node->prev = head;
            head = new_node;
        } else {
            new_node->next = head;
            new_node->prev = head->prev;
            head->prev->next = new_node;
            head->prev = new_node;
            head = new_node;
        }
    }

    void push_back(T value) {
        auto new_node = new Node<T>(value);
        if (head == nullptr) {
            new_node->next = new_node;
            new_node->prev = new_node;
            head = new_node;
        } else {
            new_node->prev=head->prev;
            new_node->next =head;
            head->prev->next = new_node;
            head->prev = new_node;
        }
    }

    void pop_back() {
        if (head == nullptr) throw runtime_error("Lista Vacia"); // vacio

        if (head->prev == head) { // un nodo
            delete head;
            head=nullptr;
            return;
        }
        // 2 a mmás
        Node<T>* temp = head->prev;
        head->prev->prev->next = head;
        head->prev = head->prev->prev;
        delete temp;
    }

    void pop_front() {
        if (head==nullptr) throw runtime_error("Lista Vacia"); // vacio

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        head->prev->next = head->next;
        head->next->prev = head->prev;
        Node<T>* temp = head->next;
        delete head;
        head = temp;
    }

    void insert(T value,int posicion) {

    }


};

#endif //CIRCULAR_DOUBLY_LINKED_LIST_H
