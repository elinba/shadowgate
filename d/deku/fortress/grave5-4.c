#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GRAVEYARD;

void create() {
    ::create();
 set_exits(([
			"east" : GY_ROOMS+"grave5-3",
   "north":GY_ROOMS +"grave6-4",
   "west" : GY_ROOMS +"grave5-5",
			"south" : GY_ROOMS +"grave4-4"
  ] )); 
}
