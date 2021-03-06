#include <std.h> 
#include "../defs.h" 
inherit INH+"spidershaft"; 

void create(){ 
    ::create(); 
    set_long("%^RESET%^%^ORANGE%^A webbed tunnel%^RESET%^\n"
"%^BOLD%^%^WHITE%^All around you thick, tacky strands of spider web cling to the narrow, vertical "
"burrow that you find yourself in.  The rough, jagged walls of %^BLACK%^granite %^WHITE%^appear to have " 
"naturally opened due to some sort of long forgotten seismic movement, providing a connection between the " "underground passage and the surface.  Countless generations of %^BLACK%^spiders %^WHITE%^have made their "
"homes here, filling it with layer upon layer of thick webbing.  Some are even thick enough that a careful "
"person might use them to ascend or descend the passage.  Though you are left to wonder just how big of a "
"spider there might be to create such sturdy webs.  You think you can see a way out of this mess, just above you.\n%^RESET%^"); 
    set_exits(([ 
      "northwest":UPPER"t5r3",
      "west":UPPER"t5r7",
      "southwest":UPPER"t5r1",
      "up":"/d/antioch/valley/rooms/spider2",
    ])); 
}