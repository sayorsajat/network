#ifndef ROUTING_H
#define ROUTING_H
class Obj;
#include <string>
#include <vector>
#include "messagesPassing.h"

class Router {
    public:
        Router();

        void pushMessageTo(std::string message);
        void addObjectToList(Obj* object);
    private:
        std::vector<Obj*> objectIDS;
        std::vector<std::string> messagesBuff;
        
        std::string binaryToString(std::string & input);

        void handlePacket();
};

#endif