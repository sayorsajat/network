#include <string>
#include <sstream>
#include <bitset>
///dst destination-object-name/bd 5 moles ethyl detected/stat getting ready/hst hostname/nof
class Message {
    public:
        Message(std::string destination_sys, std::string mBody, std::string mStatus = "basic", std::string src_host = "") {
            std::string dest = destination_sys;
            std::string body = mBody;
            std::string status = mStatus;
            std::string host = src_host;
        }

	private:
        std::string stringToBinary(std::string& input) {
            std::ostringstream oss;
            for(auto c : input) {
                oss << std::bitset<8>(c);
            }
            return oss.str();
        }
};

class Obj {
    public:
        std::string messageSourceHostID;
        Obj(std::string ID) {
            messageSourceHostID = ID;
        }

    private:
        std::string binaryToString(std::string& bits) {
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

        void passMessageTo(std::string destObjId, std::string messageBody, std::string messageStatus = "basic", bool isSrcHostAttached = false) {
            if(!isSrcHostAttached) {
                Message messageObject(destObjId, messageBody, messageStatus);
            } else {
                Message messageObject(destObjId, messageBody, messageStatus, messageSourceHostID);
            }
        }
};