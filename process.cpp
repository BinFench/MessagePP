//Functionality of process object.  See process.h

#include "process.h"

void Process::addToInbox(Message message) {
    numMessagesIn++;
    inbox.append(message);
}

void Process::addToOutbox(Message message) {
    numMessagesOut++;
    outbox.append(message);
}

Message Process::popFromOutbox() {
    if (numMessagesOut == 0)
        return emptyOutbox;

    numMessagesOut--;
    return outbox.pop();
}

Message Process::popFromInbox() {
    if (numMessagesIn == 0)
        return emptyOutbox;

    numMessagesIn--;
    return inbox.pop();
}

std::string Process::getProcess() {return processName;};
