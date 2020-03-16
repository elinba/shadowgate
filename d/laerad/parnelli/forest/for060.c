//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_long(
	"%^BOLD%^GREEN%^The Parnelli Forest%^RESET%^\n"+
	"You have walked into a magical forest.  The trees sway back and forth "+
	"as if hypnotized.  Leaves dance around happily in the wind.  The brush "+
	"looks as if it is glowing with pure energy.  You notice the occasional "+
	"firefly or pixie flitter through the air.  The sky above is the most "+
	"beautiful blue you have ever seen.  You feel such a serene peace here "+
	"that you just don't ever want to leave.  There is a beautiful river "+
	"off to the west and the city walls of Asgard are to the north.  "+
	"There is a shack to the north near the city wall."
    );
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for071",
	"south":"/d/laerad/parnelli/forest/for061"
    ]) );
}

void reset() {
   ::reset();
}