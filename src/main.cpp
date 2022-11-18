#include "include/Routing.h"
#include "include/messagesPassing.h"

int main() {
    Router router;
    Obj firstObj = Obj(router, "first");
    Obj secObj = Obj(router, "second");

    firstObj.passMessageTo(router, "first", "msg body", "basic", true);
    return 0;
}