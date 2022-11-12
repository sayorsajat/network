#include <string>
#include <sstream>
#include <bitset>
#include "include/messagesPassing.h"
///dst destination-object-name/bd 5 moles ethyl detected/stat getting ready/hst hostname/nof

Message::Message(std::string destination_sys, std::string mBody, std::string mStatus, std::string src_host) {
    std::string dest = destination_sys;
    std::string body = mBody;
    std::string status = mStatus;
    std::string host = src_host;
}

std::string Message::stringToBinary(std::string& input) {
    std::ostringstream oss;
    for(auto c : input) {
        oss << std::bitset<8>(c);
    }
    return oss.str();
}


Obj::Obj(std::string ID) : messageSourceHostID(ID) {
}

std::string Obj::binaryToString(std::string& bits) {
    std::stringstream sstream(bits);
    std::string output;
    while(sstream.good())
    {
        std::bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }

    return output;
}

void Obj::passMessageTo(std::string destObjId, std::string messageBody, std::string messageStatus, bool isSrcHostAttached ) {
    if(!isSrcHostAttached) {
        Message messageObject(destObjId, messageBody, messageStatus);
    } else {
        Message messageObject(destObjId, messageBody, messageStatus, messageSourceHostID);
    }
}