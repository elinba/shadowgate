#include <std.h>
inherit ROOM;

void place_board()
{
  string which, desc;
  object ob;
  which = "warlock";
  desc = "warlock";
  if (!objectp(present("board", TO))) {
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", which }) );
    ob->set_board_id(which);
    ob->set("short", "OOC "+desc+" board");
    ob->set("long", "OOC "+desc+" board");
    ob->set_max_posts(50);
    ob->set_location("/d/common/boards/warlockboard");
    ob->set_ooc_board(1);
    ob->set_no_clean(1);  // so they don't dest while someone is posting, etc.
  }
}

void create(){
    ::create();
    set_no_clean(1);
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no teleport",1);
    set_short("Warlocks' board room");
    set_long("Just one of the rooms housing a board.  Nothing more, nothing less.");
    set_exits( ([ "out" : "/d/dagger/boards_portal", ]) );
}

void reset() 
{
    ::reset();
    place_board();
}
