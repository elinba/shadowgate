//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains55",
	"east":"/d/laerad/plains/plains74",
	"south":"/d/laerad/plains/plains67"
    ]) );
}
