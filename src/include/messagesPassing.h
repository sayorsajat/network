#ifndef OBJ_RELATED
#define OBJ_RELATED
#include <string>
#include <memory>
#include "Routing.h"






class Message {
    public:
        std::string message;
        Message(std::string destination_sys, std::string mBody, std::string mStatus = "basic", std::string src_host = "");
        std::string stringToBinary(const std::string & input);
};

class Obj {
	public:
        std::string messageSourceHostID;
        
        Obj(std::string ID);

        void passMessageTo(Router router, std::string destObjId, std::string messageBody, std::string messageStatus = "basic", bool provideSrcHost = false);
    private:
        std::string binaryToString(std::string& bits);
};

#endif
