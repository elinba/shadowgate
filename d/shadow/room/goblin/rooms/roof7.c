#include <std.h>
#include "/d/shadow/room/goblin/short.h"

inherit "/d/shadow/room/goblin/rooms/roof2";
 
void create() {
    ::create();
    set_exits(([
        "down": RPATH "tower7",
    ]));
}

void reset() {
    ::reset();
}
