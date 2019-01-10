//Object that defines communication between processes.
//Message contains single data parameter.  Multiple parameters require passing
//the process a pointer to an array of messages.
//Messages are secure.  Once constructed, they cannot be edited.
//It is the programmer's discretion to ensure the authenticity of the message.

#include <string>
#include <sstream>
#include "data.h"

enum Types {NUM, STRING, BOOL, Null};

class Message {
public:
    std::string getMessage();
    std::string getID();
    std::string getTo();
    std::string getFrom();
    Types getType();
    Data getData();
    double getData(double ignore = 0);
    std::string getData(std::string ignore = "");
    bool getData(bool ignore = false);
    Message();
    Message(std::string iD, std::string To, std::string From,  std::string messageData, Data &data);
    Message(std::string iD, std::string To, std::string From,  std::string messageData, double &data);
    Message(std::string iD, std::string To, std::string From,  std::string messageData, std::string &data);
    Message(std::string iD, std::string To, std::string From,  std::string messageData, bool &data);

private:
    std::string to;
    std::string from;
    std::string id;
    std::string message;
    Types type;
    Data data;
};
