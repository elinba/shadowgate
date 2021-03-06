#include <std.h>
#include "../dragon.h";

inherit BSEWER;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long(
      "%^BOLD%^%^BLACK%^This is a wider section of tunnel under the city of Sanctuary. This"+
      " tunnel is dry compared to the other tunnels in these sewers. Faintly"+
      " luminescent lichen clings to the dark walls, reflecting lightly off"+
      " the water that occasionally drip from the ceiling to the tunnel. The"
      " tunnel extends to either north or south."
    );
    set_exits(([
       "north" : SEWER+"sewer48",
       "south" : SEWER+"sewer46"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
    set_property("no teleport", 1);
    set_smell("default","The rotting smell of waste is very strong in these tunnels.");
}
