//Implementation of linked.h

#include "linked.h"

template <typename Type>
void linkedList<Type>::append(Type newdata) {
    Node<Type>* node = new Node<Type>();
    node->data = newdata;
    last->next = node;
    last = node;
};

template <typename Type>
Type linkedList<Type>::pop() {
    Node<Type>* toDelete = start;
    Type toReturn = toDelete->message;
    start = start->next;
    delete toDelete;
    return toReturn;
};

template <typename Type>
linkedList<Type>::linkedList() {
    start = NULL;
    last = NULL;
};
