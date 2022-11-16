#ifndef ROUTING_H
#define ROUTING_H

#include <string>
#include <vector>

class Router {
    public:
        Router();

        void pushMessageTo(std::string message);
    private:
        std::vector<std::string> messagesBuff;
        
        std::string binaryToString(std::string & input);

        void handlePacket();
};

#endif