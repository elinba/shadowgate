#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit RIVERBANK;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^CYAN%^The river runs out "+
    "of the forest from the northwest and continues southeast into "+
    "the forest.  Travel is made impossible by the thick "+
    "undergrowth that covers the ground near the river to the "+
    "northwest.%^RESET%^");
    set_exits(([
       "east" : F_ROOMS"36-15",
       "north" : F_ROOMS"37-16",
       "southeast" : F_ROOMS"36-14",
       "northeast" : F_ROOMS"36-16"       
    ] ));
}
