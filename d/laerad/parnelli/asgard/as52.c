//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_name("North Thunder road");
    set_short("North Thunder road");
    set_long(
	"%^BOLD%^North Thunder road%^RESET%^
You are on one of Asgard's central roads.  The cobblestone street leads east "+
	"towards the back gates of Asgard and west towards the inner city.  "+
	"You can see the backs of tall buildings and warehouses to the "+
	"north and a dark looming tower to the south."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","Silence dominates this road.");
*/
    set_exits( ([
	"east":"/d/laerad/parnelli/asgard/as54",
	"west":"/d/laerad/parnelli/asgard/as50"
    ]) );
}
/*
void reset(){
    ::reset();
    if(!present("guard")){
	new("/d/laerad/mon/rguard")->move(this_object());
    }
}
*/