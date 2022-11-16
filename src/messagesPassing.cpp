#include <string>
#include <sstream>
#include <bitset>
#include <iostream>
#include "include/messagesPassing.h"
#include "include/Routing.h"
///dst destination-object-name/bd 5 moles ethyl detected/stat getting ready/hst hostname/nof

// ParentObj::ParentObj() {
// }

// ParentObj* ParentObj::make_object(std::string id) {
//     // factoryObj.objectIDS.push_back(id);
//     return new Obj(id);
// };

Message::Message(std::string destination_sys, std::string mBody, std::string mStatus, std::string src_host) : message("/dst " + destination_sys + "/bd " + mBody + "/stat " + mStatus + "/hst " + src_host + "/nof") {
}

std::string Message::stringToBinary(const std::string & input) {
    std::ostringstream oss;
    for(auto c : input) {
        oss << std::bitset<8>(c);
    }
    return oss.str();
}

Obj::Obj(std::string ID) {
    Obj::messageSourceHostID = ID;
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