#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"28-2",
       "east" : F_ROOMS"26-2",
       "north" : F_ROOMS"27-3",
       "south" : F_ROOMS"27-1",
       "southeast" : F_ROOMS"26-1",
       "southwest" : F_ROOMS"28-1",
       "northeast" : F_ROOMS"26-3",
       "northwest" : F_ROOMS"28-3",
    ] ));
}
