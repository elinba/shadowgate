
#include <std.h>
inherit "/d/attaya/tower/spec/tower";

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("Inside the walls of the Tower of the Black Dawn.");
     set_long("
    This is the northeast guard tower.  Benches are built into all four walls, and firing slits have been cut in the floor and the walls.  An empty weapon rack is built into the north wall.
");

    set_exits( ([
    "west" : "/d/attaya/tower/floor10",
        ]) );
   set_listen("default", "The sound of rushing water is somewhat muffled in here.");
    set_items(([
    "benches" : "Wooden benches are built into the north, south, and east walls.",
    "slits" : "Looking out, you can see the walkway, and the water far below.",
    "rack" : "All the weapons have been removed from this wooden weapon rack.",
    ]));

}
void init(){
   ::init();
  do_random_encounters(({"/d/attaya/mon/banisher.c"}),50,1);
  do_random_encounters(({"/d/attaya/mon/banisher.c"}),50,1);
  do_random_encounters(({"/d/attaya/mon/archer.c"}),50,1);
  do_random_encounters(({"/d/attaya/mon/uwarrior.c"}),50,1);
  do_random_encounters(({"/d/attaya/mon/phalanx.c"}),50,1);
  do_random_encounters(({"/d/attaya/mon/warlock.c"}),50,1);
  do_random_encounters(({"/d/attaya/mon/archer.c"}),50,1);
  do_random_encounters(({"/d/attaya/mon/knight.c"}),50,1);
  do_random_encounters(({"/d/attaya/mon/knight2.c"}),50,1);
  do_random_encounters(({"/d/attaya/mon/solstice.c"}),25,1);

   }

