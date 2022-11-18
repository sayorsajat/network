#include <string>
#include <sstream>
#include <bitset>
#include <iostream>
#include "include/messagesPassing.h"
#include "include/Routing.h"
///dst destination-object-name/body 5 moles ethyl detected/topic getting ready/hst hostname/nof

Obj::Obj(Router & router, std::string ID) {
    Obj::messageSourceHostID = ID;
    router.addObjectToList(this);
};

void Obj::receiveMessage(Message_T message) {
    
};

void Obj::passMessageTo(Router router, std::string destObjId, std::string messageBody, std::string messageStatus, bool provideSrcHost) {
    if(!provideSrcHost) {
        Message messageObject(destObjId, messageBody, messageStatus);
        std::string strMessage = messageObject.message;
        std::string binary = messageObject.stringToBinary(strMessage);
        router.pushMessageTo(binary);
    } else {
        Message messageObject(destObjId, messageBody, messageStatus, messageSourceHostID);
        std::string strMessage = messageObject.message;
        std::string binary = messageObject.stringToBinary(strMessage);
        router.pushMessageTo(binary);
    }
};

Message::Message(std::string destination_sys, std::string mBody, std::string topic, std::string src_host) : message("/dst " + destination_sys + "/body " + mBody + "/topic " + topic + "/hst " + src_host + "/nof") {
}

std::string Message::stringToBinary(const std::string & input) {
    std::ostringstream oss;
    for(auto c : input) {
        oss << std::bitset<8>(c);
    }
    return oss.str();
}
