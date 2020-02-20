/*
  acompanion.c
  
  Animal companion for rangers. Will be fleshed
  out more over time.
  
  -- Tlaloc --
*/

inherit WEAPONLESS;

#include <daemons.h>

#define SAVEDIR "/d/save/summons/" + owner->query_name() + "/animal/"

object owner,
       *link_buffs;   //Companion gets buffs

string saved_short,
       saved_long;

int setup;

int set_owner(object ob) { owner = ob; return 1; }
object query_owner()     { return owner; }

void create(){
    ::create();
    set_name("companion");
    set_id(({"companion", "greater summon"}));
    set_short("A generic animal companion");
    set_hd(4,1);
    set_hp(40);
    set_exp(1);
    set_damage(2, 6);
    set_size(2);
    set_gender("neuter");
    setup = 0;
    set_funcs( ({ "special_attack" }) );
    set_func_chance(35);
}

void init()
{
    ::init();
    
    if(this_player() != owner)
        return;
    
    saved_short = read_file(SAVEDIR + "short");
    saved_long = read_file(SAVEDIR + "long");
    
    //Use read_file here - don't want to save whole object for 2 variables
    if(!strlen(saved_short) && !strlen(saved_long))
    {
        mkdir("/d/save/summons/" + this_player()->query_name());
        mkdir(SAVEDIR);
    }
    else
    {
        set_short(saved_short);
        set_long(saved_long);
    }
    
    add_action("set_animal_desc", "animal");
}

int set_animal_desc(string str)
{
    string *input;
    
    if(this_player() != owner)
        return 0;
    
    input = explode(str, " ");
    
    if(sizeof(input) < 2)
    {
        tell_object(this_player(), "Syntax : animal [long/short] [description].");
        return 1;
    }
    
    switch(input[0])
    {
        case "short":
        this_object()->set_short(implode(input[1..], " "));
        tell_object(this_player(), "Your Animal Companion will now be seen as: \n" + query_short());
        rm(SAVEDIR + "short");
        write_file(SAVEDIR + "short", query_short());
        break;
        case "long":
        this_object()->set_long(implode(input[1..], " "));
        tell_object(this_player(), "Your Animal Companion will now be described as: " + query_long());
        rm(SAVEDIR + "long");
        write_file(SAVEDIR + "long", query_long());
        break;
        default:
        tell_object(this_player(), "Please select 'long' or 'short' as options.");
        return 1;
        break;
    }
    
    return 1;
}
    

void heart_beat()
{

    object *attackers,
           room;
           
    ::heart_beat();
    
    room = environment(this_object());
    
    if(!objectp(owner) || owner->query_property("animal_companion") != this_object())
    {
        this_object()->remove();
        return;
    }
    
    //Faithful companion finds his master
    if(objectp(owner) && room != environment(owner))
        this_object()->move(environment(owner));
    
    //Companion hides if master is hiding
    if(!this_object()->query_invis())
    {
        if(owner->query_hidden() || owner->query_invis())
        {
            this_object()->set_invis(1);
            tell_object(owner, "Your animal companion fades into the shadows.");
        }
    }
    else
    {
        if(!owner->query_hidden() && !owner->query_invis())
            this_object()->set_invis(0);
    }
    
    attackers = owner->query_attackers();
    
    if(sizeof(attackers))
    {
        foreach(object ob in attackers)
            this_object()->kill_ob(ob);
    }
    else
        add_hp(query_max_hp() / 25);
}

void special_attack(object target)
{
    string tname, aname, mess;
    object room;
    
    if(!target || !objectp(target))
        return;
    
    tname = target->query_name();
    aname = capitalize(this_object()->query_name());
    room = environment(this_object());
    
    if(environment(target) != room)
        return;
    
    switch(query_name())
    {
        case "ape":
        case "badger":
        case "bear":
        tell_room(room, sprintf("%s bites %s.", aname, tname));
        tell_room(room, sprintf("%s claws %s twice.", aname, tname));
        target->do_damage("torso", roll_dice(1, 6));
        target->do_damage("torso", roll_dice(2, 4));
        break;
        case "bird":
        tell_room(room, sprintf("%s swoops in and bites %s.", aname, tname));
        tell_room(room, sprintf("%s claws %s with its talons twice.", aname, tname));
        target->do_damage("torso", roll_dice(1, 4));
        target->do_damage("torso", roll_dice(2, 4));
        break;
        case "boar":
        tell_room(room, sprintf("%s gores %s.", aname, tname));
        target->do_damage("torso", roll_dice(1, 8));
        break;
        case "camel":
        tell_room(room, sprintf("%s spits on %s.", aname, tname));
        target->do_damage("torso", roll_dice(1, 4));
        target && "/std/effect/status/sickened"->apply_effect(target,2);
        break;
        case "lion":
        tell_room(room, sprintf("%s bites %s.", aname, tname));
        tell_room(room, sprintf("%s claws %s twice.", aname, tname));
        target->do_damage("torso", roll_dice(1, 8));
        target->do_damage("torso", roll_dice(2, 6));
        break;
        case "cheetah":
        tell_room(room, sprintf("%s bites and trips %s.", aname, tname));
        tell_room(room, sprintf("%s claws %s twice.", aname, tname));
        target->do_damage("torso", roll_dice(1, 6));
        target->do_damage("torso", roll_dice(2, 3));
        target && target->set_tripped(1, "%^WHITE%^You are struggling to regain your footing!%^RESET%^");
        break;
        case "crocodile":
        tell_room(room, sprintf("%s bites %s.", aname, tname));
        tell_room(room, sprintf("%s slaps %s with its tail.", aname, tname));
        target->do_damage("torso", roll_dice(1, 8));
        target->do_damage("torso", roll_dice(1, 12));
        break;
        case "dinosaur":
        tell_room(room, sprintf("%s bites %s.", aname, tname));
        tell_room(room, sprintf("%s claws %s twice.", aname, tname));
        tell_room(room, sprintf("%s rakes %s with its talons twice.", aname, tname));
        target->do_damage("torso", roll_dice(1, 6));
        target->do_damage("torso", roll_dice(2, 4));
        target->do_damage("torso", roll_dice(2, 8));
        break;
        case "dog":
        tell_room(room, sprintf("%s bites %s.", aname, tname));
        target->do_damage("torso", roll_dice(1, 6));
        break;
        case "horse":
        tell_room(room, sprintf("%s bites %s.", aname, tname));
        tell_room(room, sprintf("%s kicks %s with its hooves twice.", aname, tname));
        target->do_damage("torso", roll_dice(1, 4));
        target->do_damage("torso", roll_dice(2, 6));
        break;
        case "snake":
        tell_room(room, sprintf("%s bites %s.", aname, tname));
        target->do_damage("torso", roll_dice(1, 4));
        POISON_D->ApplyPoison(target, "black_adder_venom", this_object(), "injury");
        break;
        case "wolf":
        tell_room(room, sprintf("%s bites and trips %s.", aname, tname));
        target->do_damage("torso", roll_dice(1, 6));
        target && target->set_tripped(1, "%^WHITE%^You are struggling to regain your footing! %^RESET%^");
        break;
    }   
    
    return;
}
    
void die(object ob)
{
    owner && tell_object(owner, "%^RED%^Your animal companion screams in agony as it passes from this world!%^RESET%^");
    owner && owner->remove_property("animal_companion");
    remove();
}

int remove()
{
    all_inventory(this_object())->remove();
    owner && owner->remove_property("animal_companion");
    ::remove();
    return 1;
}
