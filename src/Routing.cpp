#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <sstream>
#include "include/messagesPassing.h"
#include "include/Routing.h"

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
        std::string destination = decoPacket.substr(decoPacket.find("/dst ") + 5, (decoPacket.find("/bd") - (decoPacket.find("/dst ") + 5)));
        messagesBuff.pop_back();
    }
};

void Router::pushMessageTo(std::string message) {
    messagesBuff.push_back(message);
    handlePacket();
};

void Router::addObjectToList(Obj* object) {
    objectIDS.push_back(object);
}