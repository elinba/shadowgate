#include <std.h>
inherit ROOM;

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("no teleport", 1);
    set_terrain(BARREN);
    set_travel(DECAYED_FLOOR);
    set_name("A trail through the forest");
    set_short("%^BOLD%^%^GREEN%^A trail through the forest%^RESET%^");
    set_long("%^BOLD%^%^GREEN%^A trail through the forest%^RESET%^\n"
"%^RESET%^This rough %^ORANGE%^trail %^RESET%^allows a little space to move within the otherwise overgrown forest around you, though it has nearly faded entirely from disuse.  Trees rise up on "
"all sides of you, their rough-barked trunks of white and gray and black standing in stark contrast against the %^GREEN%^v%^YELLOW%^i%^BOLD%^%^WHITE%^b%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^a"
"%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^t %^RESET%^foliage that springs from every branch.  Cycads and ferns lift in sudden bursts of %^GREEN%^gr%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^en%^CYAN%^er"
"%^GREEN%^y %^RESET%^from the forest floor, while tangled vines drape from boughs above.  What few patches of soil show beneath the thick growth reveal a startling shade of %^RED%^o%^ORANGE%^c"
"%^RED%^h%^ORANGE%^r%^RED%^e%^RESET%^, perhaps hinting at some metallic residue within the earth itself.  It is very %^MAGENTA%^quiet %^RESET%^here, though the silence is broken by an "
"occasional rustle, or the eerie wailing call of some distant creature.\n");

    set_smell("default","The air is crisp and clear.");
    set_listen("default","Only the occasional rustle of leaf or the call of an unseen creature breaks the silence.");
    set_listen("call","The eerie, resonant call of some unseen creature, perhaps a bird, occasionally shatters the forest's tranquility to echo out through the trees.");
    set_exits( ([
        "northeast" : "/d/hm_quest/rooms/quest7",
        "west" : "/d/hm_quest/rooms/quest9",
    ]) );
    set_items(([
      "trail" : "%^RESET%^The trail you're on is mostly %^GREEN%^ov%^ORANGE%^e%^GREEN%^rg%^ORANGE%^ro%^GREEN%^wn %^RESET%^and long since abandoned, though it allows for a somewhat easier "
"passage through the dense forest.",
      ({ "trees", "forest", "foliage" }) : "%^RESET%^Ancient trees loom up around you on all sides, their branches clawing towards the sky and their %^GREEN%^fo%^BOLD%^l%^YELLOW%^i%^RESET%^"
"%^GREEN%^a%^ORANGE%^g%^GREEN%^e %^RESET%^obscuring it almost entirely from view.  They seem of a kind not found elsewhere, their %^BOLD%^%^WHITE%^gh%^RESET%^o%^BOLD%^%^BLACK%^s%^RESET%^t"
"%^BOLD%^%^WHITE%^ly %^RESET%^trunks of white and gray and black standing in stark contrast to the vibrant hue of their leaves.  To the northeast, the trees seem to thin a little, and you can "
"hear the distant crash of the ocean beyond.",
      ({ "cycads", "ferns", "grass", "earth", "soil" }) : "%^RESET%^The lower layer of the forest is populated by sprays of green, lifting from fern fronds and the %^BOLD%^%^BLACK%^blackened "
"%^RESET%^trunks of countless cycads.  Where they and the patches of grass between don't quite cover the soil, it shows in a startling shade of %^RED%^o%^ORANGE%^c%^RED%^h%^ORANGE%^r%^RED%^e"
"%^RESET%^.",
      "vines" : "%^RESET%^Vines drape %^CYAN%^lazily %^RESET%^from the limbs above, trailing their leaves and fruits as they tangle and fall.",
    ]));
    add_pre_exit_function("northeast","GoThroughDoor");
}

int GoThroughDoor() {
    tell_object(TP,"%^BOLD%^%^WHITE%^You push your way out from among the trees and finally find your way unimpeded, as your feet sink into shifting sand.%^RESET%^");
    if(!TP->query_invis())
      tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" presses on further through the trees and finally emerges from the forest.%^RESET%^",TP);
    return 1;
}