#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_13,1",
        "east"      :DES+"desert_14,2",
        "west"      :DES+"desert_14,0"
             ]));
}