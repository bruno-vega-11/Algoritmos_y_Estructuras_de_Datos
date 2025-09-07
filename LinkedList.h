//
// Created by Usuario on 6/09/2025.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T val;
    Node* next;
    Node(T value):val(value),next(nullptr){};
    Node(T value,Node* next_):val(value),next(next_){};
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList(): head(nullptr){};
    ~LinkedList(){};
    void print() {
        if (empty()) throw std::runtime_error("Lista vacía");
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->val;
            if (temp->next != nullptr) cout << ", ";
            temp = temp->next;
        }
        cout << endl;
    }
    T front() {
        if (empty()) throw std::runtime_error("Lista vacía");
        return head->val;
    }
    T back() {
        if (empty()) throw std::runtime_error("Lista vacía");
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp= temp->next;
        }
        return temp->val;
    }
    void push_front(T valor) {
        auto* new_head = new Node<T>(valor,head);
        head = new_head;
    }
    void push_back(T valor) {
        auto* new_element = new Node<T>(valor,nullptr);
        if (empty()) {
            head = new_element;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_element;
    }
    void pop_front() {
        if (empty()) throw std::runtime_error("Lista vacia");
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
    }
    void pop_back() {
        if (empty()) throw std::runtime_error("Lista vacia");

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return ;
        }
        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    T operator[](int posicion) {
        // Las posiciones empiezan del 0
        if (posicion < 0 or empty()) throw out_of_range("Indice incorrecto");
        Node<T>* temp = head;
        for (int i = 0 ; i < posicion ; i++) {
            if (temp == nullptr) throw std::out_of_range("Indice incorrecto");
            temp= temp->next;
        }
        if (temp == nullptr) throw std::out_of_range("Indice incorrecto");
        return temp->val;
    }
    bool empty() {
        if (head == nullptr) {
            return true;
        }
        return false;
    }
    int size() {
        int size = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        return size;
    }
    void clear() {
        Node<T>* temp = head;
        while (head!=nullptr) {
            temp = temp->next;
            delete head;
            head = temp;
        }
    }
    void sort() {
        if (head == nullptr) return;
        Node<T>* ult = nullptr;
        while (head!=ult) {
            Node<T>* actual = head;
            while (actual->next != ult) {
                if (actual->val > actual->next->val) {
                    auto temp = actual->next->val;
                    actual->next->val = actual->val;
                    actual->val = temp;
                }
                actual = actual->next;
            }
            ult= actual;
        }

    }

    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};
#endif //LINKEDLIST_H
