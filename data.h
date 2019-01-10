//Under the hood object for storing various data.
//Technically all message data is stored in Data,
//but Data is directly accessed by the programmer
//when sending object types or appending multiple
//items to a single datatype. Also a linked list.

#include <cstddef>

class Data {
public:
    bool isLastNode();
    bool isFirstNode();
    void* getData();
    Data getNext();
    Data getLast();
    void insertNext(Data *newData);
    void insertFront(Data *newData);
    void insertEnd(Data *newData);
    Data pop();

    void* data;
    Data* next;
    Data* previous;

    Data();
    Data(void* newData);

private:
    void setFirst(bool first);
    void setLast(bool last);
    bool isLast;
    bool isFirst;

};
