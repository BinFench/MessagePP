//Object that defines communication between processes.
//Message contains single data parameter.  Multiple parameters require passing
//the process a pointer to an array of messages.
//Messages are secure.  Once constructed, they cannot be edited.
//It is the programmer's discretion to ensure the authenticity of the message.

#include <string>
#include <sstream>

enum Types {NUM, STRING, BOOL, Null};

template <typename Type>
class Message {
public:
    std::string getMessage();
    std::string getID();
    std::string getTo();
    std::string getFrom();
    Types getType();
    Type getData();
    Message();
    Message(std::string iD, std::string To, std::string From, Types messageType, std::string messageData, Type Data);

private:
    std::string to;
    std::string from;
    std::string id;
    std::string message;
    Types type;
    Type data;
};

template <typename Type>
Message<Type> createMessage(std::string id, std::string to, std::string from, Types messageType, std::string messageData, Type Data) {return Message<Type>(id, to, from, messageType, messageData, Data);};
