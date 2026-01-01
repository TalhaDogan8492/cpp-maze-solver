#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

template <typename T>
class Stack {
private:
    struct Node {
        T data; 
        Node* next;
    };
    Node* topNode;

public:
    Stack() { topNode = NULL; } 

    ~Stack() {
        while (!isEmpty()) pop();
    }

    void push(T value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    T peek() {
        if (!isEmpty()) return topNode->data;
        throw "Stack Bos";
    }

    bool isEmpty() {
        return topNode == NULL;
    }
};

#endif