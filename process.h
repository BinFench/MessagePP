//Object that helps to segregate functions into a stateless functional basis.
//Usage to the discretion of the programmer.  Is intended to use messages to
//determine state and filter out incorrect input.
//Output is stream of messages for communication with other processes.

#include "linked.h"

template <typename Type>
class Process {
public:
    virtual void run();
    Process();
    void addToInbox(Message<Type> message);
    Message<Type> popFromOutbox();
    std::string getProcess();
    bool isOutboxLocked();
    bool isRunning();
    bool isParallel();
    bool isEmptyIn();
    bool isEmptyOut();

    Message<Type> emptyOutbox;

protected:
    virtual void unpack();
    void addToOutbox(Message<Type> message);
    Message<Type> popFromInbox();

    linkedList<Type> inbox;
    linkedList<Type> outbox;
    int numMessagesIn = 0;
    int numMessagesOut = 0;
    std::string processName;
    bool outboxLock;
    bool running;
    bool parallel;
};
