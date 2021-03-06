//signet rings for Lothwaite - by Circe 6/21/04
#include <std.h>
#include <move.h>
#include <security.h>
#include "../lothwaite.h"
#include "signet_ring.h"

#define SYMBOLS ({"eagle","doe","rabbit","fox","lion","hawk","serpent","unicorn","oak","raven","phoenix","dragon","spider","web","bees","snowflake","griffon","scorpion","wolf","stag","bear","crown","jewel","panther","eye","dice","knight","rook"})

#define WEAPONS ({"battleaxe","axes","longsword","short sword","dagger","warhammer","spears","mace","scepter","rapier","flail","scimitar","quarterstaff","bardiche","bastard sword","lance","whip","trident","gauntlet","book","scythe","sickle","morning star","bow","lute"})

#define BACKGROUNDS ({"waterfall","forest","valley","mountains","desert","city",\
"wheat field","caves","dwarven city","treetop village","evergreens","ocean",\
"monolith","full moon","crescent moon","steppe","grasslands","winding path",\
"justice scales","pyramid","ivy","flames","iceberg","snowcapped peak","maze",\
"chess board","castle"})
inherit OBJECT;

string FILE;

void finish();

int save_me(string file){ return 1;}

void exit(){
   TP->add_money("gold",2500);
   tell_object(TP,"Edric returns your 2500 gold coins.");
   rm(FILE);
   remove();
}

void set_file_name(string f) {
    FILE = f;
}

void init(){
   ::init();
   seteuid(UID_RESTORE);
   WF(HEADER);
   WF(NAME);
   WF(ID);
   WF(SHORT);
   write("%^BOLD%^%^RED%^NOTE: %^WHITE%^Once you complete the order "+
      "for a ring, you will be unable to change the design - %^RED%^EVER"+
      "%^WHITE%^.  Be sure you choose something that fits your character.  "+
      "Use ** to cancel your order.%^RESET%^\n\n");
   write("%^GREEN%^Please choose the symbol you would like for your "+
      "ring from the list below.%^RESET%^\n");
   write("%^GREEN%^------------------------- %^YELLOW%^Symbols %^RESET%^%^GREEN%^-------------------------");
   write(
@CIRCE
   eagle       doe        rabbit      fox
   lion        hawk       serpent     unicorn
   oak         raven      phoenix     dragon
   spider      web        bees        snowflake
   griffon     scorpion   wolf        stag
   bear        crown      jewel       panther
   eye         dice       knight      rook   
CIRCE
   );
   input_to("mysymbol");
}

int mysymbol(string str){
   if(!str){
      write("%^BOLD%^You must choose a symbol for your ring from the "+
         "list below!  If you wish to cancel your order, use **.");
      write("%^GREEN%^------------------------- %^YELLOW%^Symbols %^RESET%^%^GREEN%^-------------------------");
      write(
@CIRCE
   eagle       doe        rabbit      fox
   lion        hawk       serpent     unicorn
   oak         raven      phoenix     dragon
   spider      web        bees        snowflake
   griffon     scorpion   wolf        stag
   bear        crown      jewel       panther
   eye         dice       knight      rook   
CIRCE
      );
      input_to("mysymbol");
      return 1;
   }
   if(str == "**"){
      return exit();
   }
   if(member_array(str,SYMBOLS) == -1){
      write("%^BOLD%^%^RED%^That is not a valid symbol!\n");
      write("%^BOLD%^Please choose the symbol you would like on your ring.\n"+
      "You may choose any of the following:%^RESET%^\n\n");
      write("%^GREEN%^------------------------- %^YELLOW%^Symbols %^RESET%^%^GREEN%^-------------------------");
      write(
@CIRCE
   eagle       doe        rabbit      fox
   lion        hawk       serpent     unicorn
   oak         raven      phoenix     dragon
   spider      web        bees        snowflake
   griffon     scorpion   wolf        stag
   bear        crown      jewel       panther
   eye         dice       knight      rook   
CIRCE
      );
      input_to("mysymbol");
      return 1;
   }
   switch(str){
      case "eagle":  str = "a soaring %^BOLD%^bald eagle %^RESET%^in flight";
                     break;
      case "doe":  str = "a %^RESET%^%^ORANGE%^gentle doe %^RESET%^standing peacefully";
                   break;
      case "rabbit":  str = "a small %^BOLD%^rabbit%^RESET%^";
                      break;
      case "fox":  str = "a %^RESET%^%^RED%^sly fox%^RESET%^";
                   break;
      case "lion":  str = "a proud %^YELLOW%^lion %^RESET%^with a "+
                       "%^ORANGE%^majestic mane%^RESET%^";
                   break;
      case "hawk":  str = "a wheeling %^RED%^hawk %^RESET%^gliding on "+
                       "the %^CYAN%^winds%^RESET%^";
                   break;
      case "serpent":  str = "a cunning %^GREEN%^serpent %^RESET%^coiled to strike";
                   break;
      case "unicorn":  str = "a proud %^BOLD%^unicorn %^RESET%^with her "+
                       "%^BOLD%^mane %^RESET%^rippling in the %^CYAN%^breeze%^RESET%^";
                   break;
      case "oak":  str = "an ancient %^GREEN%^oak tree %^RESET%^with spreading branches";
                   break;
      case "raven":  str = "a %^BOLD%^%^BLACK%^black-winged raven "+
                       "%^RESET%^floating on the winds";
                   break;
      case "phoenix":  str = "a %^BOLD%^%^RED%^fi%^YELLOW%^e%^RED%^ry "+
                       "phoenix %^RESET%^rising from the %^BOLD%^%^BLACK%^"+
                       "ashes%^RESET%^";
                   break;
      case "dragon":  str = "a shrewd %^BOLD%^dragon %^RESET%^atop its "+
                       "%^YELLOW%^horde%^RESET%^";
                   break;
      case "spider":  str = "a furtive %^BOLD%^%^BLACK%^spider%^RESET%^";
                   break;
      case "web":  str = "a tangle of %^BOLD%^silver spider webs%^RESET%^";
                   break;
      case "bees":  str = "a swarm of five %^YELLOW%^bees %^RESET%^"+
                       "flying a %^CYAN%^diamond-shaped pattern%^RESET%^";
                   break;
      case "snowflake":  str = "a beautiful %^BOLD%^snowflake%^RESET%^";
                   break;
      case "griffon":  str = "a proud %^ORANGE%^griffon %^RESET%^with wings outspread";
                   break;
      case "scorpion":  str = "a glittering %^BOLD%^%^BLACK%^scorpion "+
                        "%^RESET%^with tail curled";
                   break;
      case "wolf":  str = "a howling %^BOLD%^%^BLACK%^wolf%^RESET%^";
                   break;
      case "stag":  str = "a majestic %^ORANGE%^stag%^RESET%^";
                   break;
      case "bear":  str = "a massive %^ORANGE%^bear %^RESET%^standing upright";
                   break;
      case "crown":  str = "a %^YELLOW%^golden crown %^RESET%^glittering "+
                         "with %^BOLD%^je%^CYAN%^we%^WHITE%^ls%^RESET%^";
                   break;
      case "jewel":  str = "a single flawless %^BOLD%^%^CYAN%^jewel%^RESET%^";
                   break;
      case "panther":  str = "a sleek %^BOLD%^%^BLACK%^black panther "+
                         "%^RESET%^with glittering %^BOLD%^%^GREEN%^eyes%^RESET%^";
                   break;
      case "eye":  str = "an open %^BOLD%^%^BLUE%^eye%^RESET%^";
                   break;
      case "dice":  str = "a pair of %^CYAN%^dice %^RESET%^with seven showing";
                   break;
      case "knight":  str = "a %^BOLD%^noble knight %^RESET%^chess piece";
                   break;
      case "rook":  str = "a %^BOLD%^%^BLACK%^solid rook %^RESET%^chess piece";
                   break;
   }
   WF(MYSYMBOL1(str));
   write("%^BOLD%^Please choose the weapon you would like for your "+
      "ring from the list below.\n");
   write("%^GREEN%^------------------------- %^YELLOW%^Weapons %^RESET%^%^GREEN%^-------------------------");
   write(
@CIRCE
   battleaxe   axes       longsword   short sword
   dagger      warhammer  spears      mace
   scepter     rapier     flail       scimitar
   bardiche    lance      whip        quarterstaff
   trident     gauntlet   book        bastard sword
   scythe      sickle     bow         morning star
   lute
CIRCE
   );
   input_to("myweapon");
   return 1;
}

void myweapon(string str){
   if(!str){
   write("%^BOLD%^You must choose a weapon for your ring.  If you want "+
      "to cancel your order, use **.%^RESET%^\n\n");
      write("%^GREEN%^------------------------- %^YELLOW%^Weapons %^RESET%^%^GREEN%^-------------------------");
      write(
@CIRCE
   battleaxe   axes       longsword   short sword
   dagger      warhammer  spears      mace
   scepter     rapier     flail       scimitar
   bardiche    lance      whip        quarterstaff
   trident     gauntlet   book        bastard sword
   scythe      sickle     bow         morning star
   lute
CIRCE
      );
      input_to("myweapon");
      return;
   }
   if(str == "**"){
      return exit();
   }
   if(member_array(str,WEAPONS) == -1){
      write("%^BOLD%^%^RED%^That is not a valid weapon!\n");
      write("%^BOLD%^Please choose the weapon you would like to have featured on your "+
      "ring from the following list:%^RESET%^\n\n");
      write("%^GREEN%^------------------------- %^YELLOW%^Weapons %^RESET%^%^GREEN%^-------------------------");
      write(
@CIRCE
   battleaxe   axes       longsword   short sword
   dagger      warhammer  spears      mace
   scepter     rapier     flail       scimitar
   bardiche    lance      whip        quarterstaff
   trident     gauntlet   book        bastard sword
   scythe      sickle     bow         morning star
   lute
CIRCE
      );
      input_to("myweapon");
      return;
   }
   switch(str){
      case "battleaxe":  str = "a war-worn %^RED%^battleaxe%^RESET%^";
                         break;
      case "axes":  str = "a pair of crossed %^GREEN%^wood axes%^RESET%^";
                   break;
      case "longsword":  str = "a slender %^BOLD%^longsword%^RESET%^";
                   break;
      case "short sword":  str = "a curving %^CYAN%^short sword%^RESET%^";
                   break;
      case "dagger":  str = "an ornate %^BOLD%^%^BLACK%^dagger%^RESET%^";
                   break;
      case "warhammer":  str = "a massive %^RED%^warhammer%^RESET%^";
                   break;
      case "spears":  str = "a pair of crossed %^ORANGE%^spears%^RESET%^";
                   break;
      case "mace":  str = "a %^BOLD%^spiked mace%^RESET%^";
                   break;
      case "scepter":  str = "a regal %^YELLOW%^scepter%^RESET%^";
                   break;
      case "rapier":  str = "a slender, curving %^BOLD%^rapier%^RESET%^";
                   break;
      case "flail":  str = "a vicious %^BOLD%^flail%^RESET%^";
                   break;
      case "scimitar":  str = "an exotic %^CYAN%^scimitar%^RESET%^";
                   break;
      case "quarterstaff":  str = "an aged %^ORANGE%^wooden quarterstaff%^RESET%^";
                   break;
      case "bardiche":  str = "a vicious looking %^RED%^bardiche%^RESET%^";
                   break;
      case "bastard sword":  str = "a massive %^BOLD%^bastard sword%^RESET%^";
                   break;
      case "lance":  str = "a fine %^YELLOW%^lance %^RESET%^crossed "+
                      "over a %^ORANGE%^carved shield%^RESET%^";
                   break;
      case "whip":  str = "a coiled %^BLUE%^scourge whip%^RESET%^";
                   break;
      case "trident":  str = "a heavily-carved %^CYAN%^trident%^RESET%^";
                   break;
      case "gauntlet":  str = "a smooth %^BOLD%^steel gauntlet%^RESET%^";
                   break;
      case "book":  str = "an open %^ORANGE%^book%^RESET%^";
                   break;
      case "scythe":  str = "a two-handed %^GREEN%^scythe %^RESET%^with blade raised";
                   break;
      case "sickle":  str = "a wickedly curving %^ORANGE%^sickle%^RESET%^";
                   break;
      case "morning star":  str = "a solid %^YELLOW%^morning star%^RESET%^";
                   break;
      case "bow":  str = "a curved %^ORANGE%^longbow %^RESET%^crossed "+
                    "with a quiver of %^BOLD%^arrows%^RESET%^";
                   break;
      case "lute":  str = "a heavily-decorated %^ORANGE%^lute%^RESET%^";
                   break;
   }
   WF(MYWEAPON1(str));
   finish();
}

void finish(){
object ob;
   WF(LONG);
   WF(WEIGHT);
   WF(VALUE);
   WF(AC);
   WF(LIMBS);
   WF(TYPE);
   WF(LORE);
   WF(LOREDIFF);
   WF(CLOSE);
   WF(SYM);
   WF(WEA);
   WF(MYSEAL10);
   WF(SEAL);
   ob = new(FILE);
   if(ob->move(TP) != MOVE_OK){
      ob->move(ETP);
   }
   write("Edric finishes your ring and gives it to you.");
   TO->remove();
   return;
}
