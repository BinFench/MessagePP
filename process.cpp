//Functionality of process object.  See process.h

#include "process.h"

void Process::addToInbox(Message message) {
    numMessagesIn++;
    Message* Messages = new Message[numMessagesIn];

    for (int i = 0; i < numMessagesIn - 1; i++)
        Messages[i] = inbox[i];

    Messages[numMessagesIn - 1] = message;

    delete inbox;

    Message* inbox = new Message[numMessagesIn];

    for (int i = 0; i < numMessagesIn; i++)
        inbox[i] = Messages[i];

    delete Messages;
}

void Process::addToOutbox(Message message) {
    numMessagesOut++;
    Message* Messages = new Message[numMessagesOut];

    for (int i = 0; i < numMessagesOut - 1; i++)
        Messages[i] = outbox[i];

    Messages[numMessagesOut - 1] = message;

    delete outbox;

    Message* outbox = new Message[numMessagesOut];

    for (int i = 0; i < numMessagesOut; i++)
        outbox[i] = Messages[i];

    delete Messages;
}

Message Process::popFromOutbox() {
    if (numMessagesOut == 0)
        return emptyOutbox;

    Message toReturn = outbox[0];

    numMessagesOut--;

    Message* Messages = new Message[numMessagesOut];

    for (int i = 1; i < numMessagesOut; i++)
        Messages[i - 1] = outbox[i];

    delete outbox;

    Message* outbox = new Message[numMessagesOut];

    for (int i = 0; i < numMessagesOut; i++)
        outbox[i] = Messages[i];

    delete Messages;

    return toReturn;
}

std::string Process::getProcess() {return processName;};
