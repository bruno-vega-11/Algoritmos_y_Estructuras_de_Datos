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
    explicit Node(T _val):val(_val),next(nullptr),prev(nullptr){};
};

template<typename T>
class CDLinkedList {
private:
    Node<T>*head = nullptr;
    int size_ = 0;
public:
    CDLinkedList():head(nullptr){};
    ~CDLinkedList(){clear();};

    T front() {
        return head->val;
    }

    T back() {
        return head->val;
    }

    void push_front(T value) {
        auto new_node = new Node<T>(value);
        if (head == nullptr) {
            new_node->next = new_node;
            new_node->prev = new_node;
            head = new_node;
        } else {
            new_node->next = head;
            new_node->prev = head->prev;
            head->prev->next = new_node;
            head->prev = new_node;
            head = new_node;
        }
        size_++;
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
        size_++;
    }

    void pop_back() {
        if (head == nullptr) throw runtime_error("Lista Vacia"); // vacio

        if (head->prev == head) { // un nodo
            delete head;
            head=nullptr;
            size_--;
            return;
        }
        // 2 a más
        Node<T>* temp = head->prev;
        head->prev->prev->next = head;
        head->prev = head->prev->prev;
        delete temp;
        size_--;
    }

    void pop_front() {
        if (head==nullptr) throw runtime_error("Lista Vacia"); // vacio

        if (head->next == head) {
            delete head;
            head = nullptr;
            size_--;
            return;
        }
        head->prev->next = head->next;
        head->next->prev = head->prev;
        Node<T>* temp = head->next;
        delete head;
        size_--;
        head = temp;
    }

    void insert(T value,int posicion) {
        if (head == nullptr) {
            auto new_node = new Node<T>(value);
            head = new_node;
            new_node->next = new_node;
            new_node->prev = new_node;
            size_++;
            return;
        }
        if (posicion<0)throw out_of_range("Rango Invalido");

        int k = posicion%size_;
        Node<T>* temp = head;
        while (k > 0) {
            temp = temp->next;
            k--;
        }
        auto new_node = new Node<T>(value);
        new_node->next = temp;
        new_node->prev = temp->prev;
        temp->prev->next = new_node;
        temp->prev = new_node;
        if (posicion % size() == 0) head = new_node;
        size_++;
    }

    void remove(int position) {
        if (head==nullptr) throw runtime_error("Lista vacia");

        if (position < 0) throw out_of_range("Rango invalido");

        int k = position%size_;
        if (size_==1) {
            delete head;
            head = nullptr;
            size_--;
            return;
        }
        Node<T>* temp = head;
        while (k >0) {
            temp = temp->next;
            k--;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp == head){head = temp->next;}
        delete temp;
        size_--;
    }

    T operator[](int position) {
        if (position < 0) throw out_of_range("Rango invalido");

        if (head==nullptr) throw runtime_error("Lista vacia");

        int k = position%size_;
        Node<T>* temp = head;
        while (k >0) {
            temp = temp->next;
            k--;
        }
        return temp->val;
    }

    bool empty() {
        if (head==nullptr){return true;}
        return false;
    }

    [[nodiscard]] int size() const {
        return size_;
    }

    void clear() {
        int k = size_;
        Node<T>* temp = head;
        if (head ==nullptr) return;
        while (k>0) {
            temp = temp->next;
            delete temp->prev;
            --k;
        }
        size_ = 0;
        head = nullptr;
    }

    void reverse() {
        if (head == nullptr)throw runtime_error("Lista Vacia");

        Node<T>* temp_1 = head;
        int k = size_;
        if (k == 1){return;}
        while (k > 0) {
            Node<T>* temp_2 = temp_1->next;
            temp_1->next = temp_1->prev;
            temp_1->prev = temp_2;

            temp_1 = temp_1->prev;
            --k;
        }
        head = head->prev;
    }
};

#endif //CIRCULAR_DOUBLY_LINKED_LIST_H
