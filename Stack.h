//
// Created by Usuario on 11/09/2025.
//

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename T>
struct element {
    T val;
    element():val(T{}){};
    explicit element(T v):val(v){}
};

constexpr int DEFAULT_MAX_SIZE = 1000;

template <typename T>
class Stack {
private:
    element<T> * arr = new element<T>[DEFAULT_MAX_SIZE]();
    size_t capacidad = DEFAULT_MAX_SIZE;
    int top_ = -1;
public:
    [[nodiscard]] bool isfull() const {
        if (top_ == capacidad-1) {
            return true;
        }
        return false;
    }

    [[nodiscard]] bool isempty() const {
        if (top_ == -1) {
            return true;
        }
        return false;
    }

    T top() {
        if (top_ == -1) throw runtime_error("Empty Stack");
        return arr[top_].val;
    }

    void push(T value) {
        if (isfull()) throw runtime_error("Stack full");
        top_++;
        arr[top_].val = value;
    }

    void pop() {
        top_--;
    }

    void resize(T new_capacity) {
        if (new_capacity <= capacidad) {
            return;
        }
        auto* new_ = new element<T>[new_capacity]();
        for (auto i : arr) {
            new_[i] = arr[i];
        }
        delete[] arr;
        arr = new_;
        capacidad = new_capacity;
    }

    ~Stack() {
        delete[]arr;
    }
};

#endif //STACK_H
