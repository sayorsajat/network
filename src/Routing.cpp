#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <sstream>
#include "include/messagesPassing.h"
#include "include/Routing.h"

Obj* Router::getObjectWithID(std::string ID) {
    
    for (auto i: objectIDS) {
        if(i->messageSourceHostID==ID) {
            return i;
        };
    };
}

std::string Router::binaryToString(std::string & bits) {
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

Router::Router() {
    std::vector<std::string> messagesBuf;
    Router::messagesBuff = messagesBuf;

    std::vector<Obj*> IDS;
    Router::objectIDS = IDS;
};

void Router::handlePacket() {
    if (!messagesBuff.empty()) {
        std::string decoPacket = binaryToString(messagesBuff[messagesBuff.size()-1]);
        std::string destinationHostID = decoPacket.substr(decoPacket.find("/dst ") + 5, (decoPacket.find("/body") - (decoPacket.find("/dst ") + 5)));
        std::string mBody = decoPacket.substr(decoPacket.find("/body ") + 6, (decoPacket.find("/topic") - (decoPacket.find("/body ") + 6)));
        std::string mTopic = decoPacket.substr(decoPacket.find("/topic ") + 7, (decoPacket.find("/hst") - (decoPacket.find("/topic ") + 7)));
        std::string host = decoPacket.substr(decoPacket.find("/hst ") + 5, (decoPacket.find("/nof") - (decoPacket.find("/hst ") + 5)));
        messagesBuff.pop_back();

        Obj* destinationHost = getObjectWithID(destinationHostID);

        Message_T messageSignature;
        messageSignature.destination = destinationHostID;
        messageSignature.body = mBody;
        messageSignature.topic = mTopic;
        messageSignature.src_host = host;

        destinationHost->receiveMessage(messageSignature);
    }
};

void Router::pushMessageTo(std::string message) {
    messagesBuff.push_back(message);
    handlePacket();
};

void Router::addObjectToList(Obj* object) {
    objectIDS.push_back(object);
}