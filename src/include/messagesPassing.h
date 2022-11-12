#ifndef OBJ_RELATED
#define OBJ_RELATED
#include <string>

class Message {
    public:
        Message(std::string destination_sys, std::string mBody, std::string mStatus = "basic", std::string src_host = "");
    private:
        std::string stringToBinary(std::string& input);
};

class Obj {
	public:
        std::string messageSourceHostID;
        Obj(std::string messageSourceHostID);
    private:
        std::string binaryToString(std::string& bits);
        void passMessageTo(std::string destObjId, std::string messageBody, std::string messageStatus = "basic", bool isSrcHostAttached = false);
};

#endif
