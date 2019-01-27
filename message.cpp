//Functionality of message object.  See message.h

#include "message.h"

template <typename Type>
Message<Type>::Message() {};

template <typename Type>
Message<Type>::Message(std::string iD, std::string To, std::string From, Types messageType, std::string messageData, Type Data) {
    id = iD;
    to = To;
    from = From;
    message = messageData;
    type = messageType;
    data = Data;
};

template <typename Type>
std::string Message<Type>::getID()        {return id;};

template <typename Type>
std::string Message<Type>::getTo()        {return to;};

template <typename Type>
std::string Message<Type>::getFrom()      {return from;};

template <typename Type>
std::string Message<Type>::getMessage()   {return message;};

template <typename Type>
Types Message<Type>::getType()            {return type;};

template <typename Type>
Type Message<Type>::getData()             {return data;};
