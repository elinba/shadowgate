
#include <std.h>
inherit ROOM;
void create(){
object ob;
:: create();
set_light(2);
set_property("indoors", 0);
set_climate("desert");
set_short("
%^ORANGE%^You are wandering in a desert.%^RESET%^
");
set_long(
@ZERINA
%^ORANGE%^You are wandering in a desert.%^RESET%^
The wind is beginning to feel rather cool now as it gently caresses your skin. You can see rocks protruding from the sand covered ground. You walk carefully onward.

ZERINA
);

set_items(([

]));

set_exits(([
"northwest" : "/d/attaya/crafters/desert/des250",
"northeast" : "/d/attaya/crafters/desert/des251",
"southwest" : "/d/attaya/crafters/desert/des296.c",
"southeast" : "/d/attaya/crafters/desert/des297.c",

]));

set_smell("default", "You can smell nothing.");
set_listen("default", "You can hear the wind as it blows the sand.");

}
