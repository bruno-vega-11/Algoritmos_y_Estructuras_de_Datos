//
// Created by Usuario on 24/09/2025.
//

#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;


template <typename T>
struct TreeNode {
    T val;
    TreeNode* izq;
    TreeNode* der;
    explicit TreeNode(T val_):val(val_),izq(nullptr),der(nullptr){};
    TreeNode(T val_,TreeNode* izq_,TreeNode* der_):val(val_),izq(izq_),der(der_){};
    ~TreeNode() = default;
};

template <typename T>
class BST {
private:
    TreeNode<T>* root;
    void insertAux(TreeNode<T>*& node,T value) {
        if (node == nullptr) {
            node = new TreeNode<T>(value);
            return;
        }
        if (node->val == value) throw runtime_error("BST already has this value");

        if (value < node->val) {
            insertAux(node->izq,value);
        } else {
            insertAux(node->der,value);
        }
    }
    bool findAux(const TreeNode<T>* node,T value) {
        if (node == nullptr) {
            return false;
        }
        if (node->val == value) {
            return true;
        }
        if (value < node->val) {
            return findAux(node->izq,value);
        } else {
            return findAux(node->der,value);
        }
    }
    void deleteAux(TreeNode<T>*& node,T value) {
        if (node->val == value) {
            if (node->izq == nullptr and node->der == nullptr) {
                // sin hijos
                delete node;
                node = nullptr;
            } else if (node->izq == nullptr) {
                // 1 hijo a la derecha
                TreeNode<T>* temp = node;
                node = node->der;
                delete temp;
            } else if (node->der == nullptr) {
                // 1 hijo a la izquierda
                TreeNode<T>* temp = node;
                node = node->izq;
                delete temp;
            } else {
                // 2 a más hijos, sucesor mínimo
                TreeNode<T>* temp = node->der;
                while (temp->izq != nullptr) {
                    temp = temp->izq;
                }
                node->val = temp->val;
                deleteAux(node->der,temp->val);
            }
        }
        if (value < node->val) {
            deleteAux(node->izq,value);
        } else {
            deleteAux(node->der,value);
        }
    }
    T minimumAux( const TreeNode<T>* node) {
        if (node==nullptr) throw runtime_error("BST is empty");
        if (node->izq == nullptr) {
            return node->val;
        }
        return minimunAux(node->izq);
    }
    T maximumAux(const TreeNode<T>* node) {
        if (node == nullptr) throw runtime_error("BST is empty");
        if (node->der == nullptr) {
            return node->val;
        }
        return maximumAux(node->der);
    }
    void printAux(const TreeNode<T>* node) {
    }
public:

    ~BST() {}
    void insert(T value) {
        insertAux(root,value);
    }
    void find(T value) {
        findAux(root,value);
    }
    void del(T value) {
        deleteAux(root,value);
    }
    T min() {
        return minimumAux(root);
    }
    T max() {
        return maximumAux(root);
    }
};

#endif //BST_H
