#ifndef OBJ_RELATED
#define OBJ_RELATED
class Router;
#include <string>
#include <memory>
#include "Routing.h"

class Message {
    public:
        std::string message;
        Message(std::string destination_sys, std::string mBody, std::string topic = "basic", std::string src_host = "");
        std::string stringToBinary(const std::string & input);
};

struct Message_T {
    std::string destination;
    std::string body;
    std::string topic;
    std::string src_host;
};

class Obj {
	public:
        std::string messageSourceHostID;
        
        Obj(Router & router, std::string ID);

        void passMessageTo(Router router, std::string destObjId, std::string messageBody, std::string messageStatus = "basic", bool provideSrcHost = false);
        void receiveMessage(Message_T message);
    private:
        std::string binaryToString(std::string& bits);
};

#endif
