#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFH;

void adjust_room(int state)
{
    string mycol;
    switch(state)
    {		
        case 0:	
            mycol = "%^BOLD%^%^WHITE%^";
            break;
        case 1:			
            mycol = "%^BOLD%^%^MAGENTA%^";
            break;
    }
    set_long(TO->query_original_long()+mycol+" The hallway continues east and west.%^RESET%^");

}

void create() 
{
    ::create();	
    set_exits((["east" : FFROOMS+"19", "west" : FFROOMS+"21" ]));		
}
