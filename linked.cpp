//Implementation of linked.h

#include "linked.h"

void linkedList::append(Message newMessage) {
    Node* node = new Node();
    node->message = newMessage;
    this->last->next = node;
    this->last = node;
};

Message linkedList::pop() {
    Node* toDelete = this->start;
    Message toReturn = toDelete->message;
    this->start = this->start->next;
    delete toDelete;
    return toReturn;
};

linkedList::linkedList() {
    this->start = NULL;
    this->last = NULL;
};
