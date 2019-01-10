//Functionality of message object.  See message.h

#include "message.h"

Message::Message() {};

Message::Message(std::string iD, std::string To, std::string From, std::string messageData, Data &data) {
    id = iD;
    to = To;
    from = From;
    message = messageData;
    type = Null;
    data = data;
};

Message::Message(std::string iD, std::string To, std::string From, std::string messageData, double &dataval) {
    id = iD;
    to = To;
    from = From;
    message = messageData;
    type = NUM;
    data = Data(static_cast<void*>(&dataval));
};

Message::Message(std::string iD, std::string To, std::string From, std::string messageData, std::string &dataval) {
    id = iD;
    to = To;
    from = From;
    message = messageData;
    type = STRING;
    data = Data(static_cast<void*>(&dataval));
};

Message::Message(std::string iD, std::string To, std::string From, std::string messageData, bool &dataval) {
    id = iD;
    to = To;
    from = From;
    message = messageData;
    type = BOOL;
    data = Data(static_cast<void*>(&dataval));
};

std::string Message::getID()        {return id;};

std::string Message::getTo()        {return to;};

std::string Message::getFrom()      {return from;};

std::string Message::getMessage()   {return message;};

Types Message::getType()            {return type;};

Data Message::getData()             {return data;};

double Message::getData(double ignore) {return *static_cast<double*>(data.getData());};

std::string Message::getData(std::string ignore) {return *static_cast<std::string*>(data.getData());};

bool Message::getData(bool ignore) {return *static_cast<bool*>(data.getData());};
