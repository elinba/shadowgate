#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(25000);
	set_id(({ "tattoo", "violet tattoo", "flame tattoo", "back tattoo", "flame", "large tattoo" }));
	set_short("%^BOLD%^%^WHITE%^A large %^RESET%^%^MAGENTA%^violet f%^BOLD%^l%^WHITE%^a%^MAGENTA%^m%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^ tattoo%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^BLACK%^An image of a violent %^RESET%^%^MAGENTA%^violet f%^BOLD%^l%^WHITE%^a%^MAGENTA%^m%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ surrounding a barbed black dagger is inked along the smooth %^WHITE%^white skin%^BLACK%^ of the half-elf's upper back almost haphazardly. Chaotic whorling tendrils of %^MAGENTA%^fire%^BLACK%^ trail away from the larger image, flowing with the natural contours of her lithe body, almost as if licking her flesh. The tempestuous flame serves as the %^MAGENTA%^v%^WHITE%^i%^MAGENTA%^vid%^BLACK%^ background for a barbed dagger positioned vertically on her lower right shoulder-blade. The wicked dagger appears to be made up of various smaller erratic images, somehow carefully arranged into one coherent form. Upon closer inspection, a small %^RESET%^j%^BOLD%^a%^RESET%^wle%^BOLD%^s%^RESET%^s sk%^BOLD%^u%^RESET%^ll%^BOLD%^%^BLACK%^ and a pair of %^WHITE%^cool %^BLACK%^gr%^RED%^a%^BLACK%^y eyes can be discerned amongst the many enigmatic and intricate details of the wicked blade.

MYLONG
	);
	set_limbs(({"torso"}));
	set_wear((:TO,"wear_me":));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "large"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

