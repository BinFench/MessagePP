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
template <typename Type>
bool Process<Type>::isOutboxLocked() {return outboxLock;};
template <typename Type>
bool Process<Type>::isRunning() {return running;};
template <typename Type>
bool Process<Type>::isParallel() {return parallel;};
template <typename Type>
bool Process<Type>::isEmptyIn() {return (numMessagesIn == 0);};
template <typename Type>
bool Process<Type>::isEmptyOut() {return (numMessagesIn == 0);};
