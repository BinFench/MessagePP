//Implementation of linked.h

#include "linked.h"

template <typename Type>
void linkedList<Type>::append(Message<Type> newMessage) {
    Node<Type>* node = new Node<Type>();
    node->message = newMessage;
    last->next = node;
    last = node;
};

template <typename Type>
Message<Type> linkedList<Type>::pop() {
    Node<Type>* toDelete = start;
    Message<Type> toReturn = toDelete->message;
    start = start->next;
    delete toDelete;
    return toReturn;
};

template <typename Type>
linkedList<Type>::linkedList() {
    start = NULL;
    last = NULL;
};
