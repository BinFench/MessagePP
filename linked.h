//Generic singly linked list for inbox/outbox of process.

#include "message.h"

template <typename Type>
class Node {
public:
    Node* next;
    Type data;
};

template <typename Type>
class linkedList {
public:
    Node<Type>* start;
    Node<Type>* last;

    linkedList<Type>();
    ~linkedList<Type>();

    void append(Type newMessage);
    Type pop();
};
