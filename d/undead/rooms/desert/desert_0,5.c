#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :DES+"desert_0,6",
        "south"     :DES+"desert_1,5",
        "west"      :DES+"desert_0,4"
             ]));
}