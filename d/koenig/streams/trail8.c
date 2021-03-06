//trail8.c - Connecting Koenig to Tabor.  Updated by Circe 11/28/03
#include <std.h>
#include "../koenig.h"
inherit TRAIL;

void create()
{
	::create();
	set_long(
	"This is a dirt path that winds its way through the lower foothills of"+
	" the mountains. It has been fairly well defined. The larger stones"+
	" have been removed completely, the smaller ones have been set on the"+
	" sides to help define it more clearly. The dirt of the path is fine,"+
	" as though it has gotten much use in its day. Your footsteps stir up"+
	" the dust as you move along the trail. A fine red film of dust has"+
	" settled itself over your belongings already.  Just to the west, a larger "+
      "path meets with this one.\n" 
	);
	set_exits(([
	"northeast" : VILSTREAM"trail7",
	"west" : "/d/shadow/room/forest/road56",
	]));
}
