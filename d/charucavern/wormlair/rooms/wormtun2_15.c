#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMTUN;

void create() 
{
    ::create();
    
    set_long(TO->query_long()+"%^BOLD%^%^MAGENTA%^ The opening of a %^RESET%^"+
    "%^ORANGE%^passageway%^BOLD%^%^MAGENTA%^ "+
    "is visible in the center of the floor here.%^RESET%^");
    
    set_climb_exits((["descend": ({WROOMS+"wormnar3_1", 20, 10, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall!^RESET%^");
    
    add_item(({"opening", "passageway"}), "%^RESET%^%^ORANGE%^This opening "+
    "reveals a passageway of dirt and stone that goes down into "+
    "darkness. You could <%^RESET%^descend%^RESET%^%^ORANGE%^> into it "+
    "if you were brave enough to do so.%^RESET%^");
    
    set_exits((["southeast" : WROOMS + "wormtun2_14"]));	
    
}
