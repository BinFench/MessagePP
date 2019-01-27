//Functionality of process object.  See process.h

#include "process.h"

template <typename Type>
void Process<Type>::addToInbox(Message<Type> message) {
    numMessagesIn++;
    inbox.append(message);
}

template <typename Type>
void Process<Type>::addToOutbox(Message<Type> message) {
    numMessagesOut++;
    outbox.append(message);
}

template <typename Type>
Message<Type> Process<Type>::popFromOutbox() {
    if (numMessagesOut == 0)
        return emptyOutbox;

    numMessagesOut--;
    return outbox.pop();
}

template <typename Type>
Message<Type> Process<Type>::popFromInbox() {
    if (numMessagesIn == 0)
        return emptyOutbox;

    numMessagesIn--;
    return inbox.pop();
}

template <typename Type>
std::string Process<Type>::getProcess() {return processName;};
