//forest70a.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "north":TFOREST"forest63",
                "south":TFOREST"forest69",
                ]));
}

