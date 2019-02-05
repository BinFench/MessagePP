//This is the default task runner.  The task runner holds all the processes
//it can run, and handles the sending/receiving of messages between processes.

#include "process.h"
template <typename Type>
class TaskHandler: public Process<Type>::Process {
public:
    void addProcess(Process<Type> process);
    void run();
private:
    linkedList<Type> processList;
    int numProcesses;
};
