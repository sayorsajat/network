#include "include/Routing.h"
#include "include/messagesPassing.h"
#include <iostream>

void secondReceiver(Message_T message) {
    std::cout << "receiver works!" << std::endl;
}


int main() {
    Router router;
    Obj firstObj = Obj(router, "first");
    Obj secObj = Obj(router, "second");
    secObj.registerReceiver("basic", secondReceiver);

    firstObj.passMessageTo(router, "second", "msg body", "basic", true);
    return 0;
}