#include <std.h>
#include "../common.h"

inherit DEEPROAD;

void create(){
    ::create();
    set_exits(([
    "east":PATH+"rp_p002_n012",
"west":PATH+"rp_p000_n012",

                   ]));

}

