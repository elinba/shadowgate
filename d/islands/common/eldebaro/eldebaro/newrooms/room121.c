#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"52",
        "east" : ELROOMSD+"122",
        "south" : ELROOMSD+"106",
        "west" : ELROOMSD+"120",
        
    ]));
}
