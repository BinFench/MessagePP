#include "taskhandler.h"
#include <future>

template <typename Type>
void TaskHandler<Type>::addProcess(Process<Type> process) {
    numProcesses++;
    processList.append(process);
};

template <typename Type>
void TaskHandler<Type>::run() {
    Node<Type>* eval = processList.start;
    while (Process<Type>::numMessagesIn > 0) {
        Message<Type> toSend = Process<Type>::inbox.pop();
        eval = processList.start;

        for (int i = 0; i < numProcesses; i++) {
            if (toSend.to == eval.data.getProcess())
                break;

            eval = eval->next;
        }

        eval.addToInbox(toSend);
    }

    eval = processList.start;
    for (int i = 0; i < numProcesses; i++) {
        if (!eval.data.isRunning() && !eval.data.isEmptyIn()) {
            if (eval.data.isParallel()) std::async(std::launch::async, eval.data.run);
            else eval.data.run();
        }

        eval = eval->next;
    }

    eval = processList.start;
    bool completed = true;
    for (int i = 0; i < numProcesses; i++) {
        if (eval.data.isRunning() || !eval.data.isEmptyOut()) {
            completed = false;
            break;
        }

        else eval = eval->next;
    }

    if (completed) return;

    eval = processList.start;
    for (int i = 0; i < numProcesses; i++) {
        while (!eval.data.isEmptyIn() && !eval.data.isOutboxLocked())
            addToInbox(eval.data.popFromOutbox());
        eval = eval->next;
    }

    eval = NULL;
};
