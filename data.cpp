//Functionality of data object.  See data.h

#include "data.h"

bool Data::isLastNode(){return isLast;};

bool Data::isFirstNode(){return isFirst;};

void* Data::getData(){return data;};

Data Data::getNext(){return next;};

Data Data::getLast() {return previous;};

void Data::insertNext(Data *newData) {
    Data* toSet = next;
    if (!next){
        toSet->previous = newData;
        next->setLast(false);
    }

    next = newData;
    next->previous = this;
    next->next = toSet;
    next->setFirst(false);
    next->setLast(!next->next);
};

void Data::insertFront(Data *newData) {
    Data *current = this;
    while (!current->previous)
        current = current->previous;

    newData->insertNext(current);
};

void Data::insertEnd(Data *newData) {
    Data current = this;
    while (!current.next)
        current = current.next;

    current.insertNext(newData);
};

Data Data::pop(){
    if (!previous) {
        Data toRet = next;
        delete this;
        return toRet;
    }

    Data toRet = previous;
    previous->next = next;

    if (!next)
        next->previous = previous;

    delete this;
    return toRet;
};

void Data::setFirst(bool first) {isFirst = first;};

void Data::setLast(bool last) {isLast = last;};

Data::Data() {
    data = NULL;
    next = NULL;
    previous = NULL;
    isLast = true;
    isFirst = true;
};

Data::Data(void* newData) {
    data = newData;
    next = NULL;
    previous = NULL;
    isLast = true;
    isFirst = true;
    };
