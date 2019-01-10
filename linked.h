//Generic singly linked list for inbox/outbox of process.

#include "message.h"

class Node {
public:
    Node* next;
    Message message;
};

class linkedList {
public:
    Node* start;
    Node* last;

    linkedList();
    ~linkedList();

    void append(Message newMessage);
    Message pop();
};
