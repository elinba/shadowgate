#include <spell.h>
inherit SPELL;

int wasbuff, lower;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("casters lament");
    set_spell_level(([ "warlock" : 4 ]));
    set_syntax("cast CLASS casters lament (on <object> [at <player>])");
    set_description("This invocation harnesses the greatest of a warlock's natural aptitude for manipulating "
"magical energies and items. For the first, if cast with no target, it will imbue the warlock with a considerable "
"resistance to magical attacks. If directed at an item, either in the caster's own inventory or in that of another "
"player, it can be used to shatter the magic upon a cursed item.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

string query_casting_string() {
    tell_object(caster,"%^MAGENTA%^You voice the words to the incantation, and your fingertips g%^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^eam with e%^RED%^ne%^MAGENTA%^r%^RED%^g%^MAGENTA%^y.%^RESET%^");
    tell_room(place,"%^MAGENTA%^"+caster->QCN+" voices an invocation, and "+caster->QP+" fingertips g%^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^eam with e%^RED%^ne%^MAGENTA%^r%^RED%^g%^MAGENTA%^y.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    string what,who;
    object ob, ob2;
    int ench;

    if(!arg) { // if no targetting, raise MR of the caster - same formula as prot from spells/etc
      if(caster->query_property("raised resistance")){
        tell_object(caster,"%^BOLD%^Your invocation conflicts with existing magic and is repelled forcibly.");
        dest_effect();
        return;
      }
      tell_object(caster,"%^MAGENTA%^You press your hands together and the energy r%^CYAN%^i%^MAGENTA%^pp%^RED%^l%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^s and flows back over itself, down your arms and over your body to encase you in protective spellcraft!%^RESET%^");
      tell_room(place,"%^MAGENTA%^"+caster->QCN+" presses "+caster->QP+" hands together and the energy r%^CYAN%^i%^MAGENTA%^pp%^RED%^l%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^s and flows back over itself, down "+caster->QP+" arms and over "+caster->QP+" body!%^RESET%^",caster);
      wasbuff = 1;
      lower = clevel;
      caster->set_property("magic resistance",lower);
      caster->set_property("raised resistance",1);
      addSpellToCaster();
      spell_successful();
      call_out("dest_effect",80 + clevel*8);
      return;
    }
    if (sscanf(arg,"%s at %s", what, who) != 2) {
        what = arg;
        who = 0;
    }
    if(!who) ob = present(what,caster);
    else {
        if((string)caster->realName(who) != "") who = (string)caster->realName(who);
        if(!ob2 = present(who, place)) {
            tell_object(caster,"That person isn't here.");
            dest_effect();
            return;
        }
        ob = present(what,ob2);
    }
    if (!objectp(ob)) {
        tell_object(caster,"That object is not present");
        dest_effect();
        return;
    }
    ench = ob->query_property("enchantment");
    if (ench > -1) {
        tell_object(caster,"That object is not cursed.");
        dest_effect();
        return;
    }
    if(ob->query_property("no remove") || ob->query_property("no remove curse")) {
        tell_object(caster,"That curse is too powerful even for you to break.");
        dest_effect();
        return;
    }
    ob->remove_property("enchantment");
    tell_object(caster,"%^MAGENTA%^You touch your hands to the "+what+" and the energy feeds into it, before s%^RED%^ha%^MAGENTA%^t%^RED%^t%^MAGENTA%^e%^RED%^ri%^MAGENTA%^ng in a b%^BOLD%^%^MAGENTA%^r%^BOLD%^%^WHITE%^i%^RESET%^%^MAGENTA%^ght bur%^BOLD%^%^MAGENTA%^s%^RESET%^%^MAGENTA%^t!%^RESET%^");
    tell_room(place,"%^MAGENTA%^"+caster->QCN+" touches "+caster->QP+" hands to the "+what+" and the energy feeds into it, before s%^RED%^ha%^MAGENTA%^t%^RED%^t%^MAGENTA%^e%^RED%^ri%^MAGENTA%^ng in a b%^BOLD%^%^MAGENTA%^r%^BOLD%^%^WHITE%^i%^RESET%^%^MAGENTA%^ght bur%^BOLD%^%^MAGENTA%^s%^RESET%^%^MAGENTA%^t!%^RESET%^",caster);
    spell_successful();
    dest_effect();
}

void dest_effect(){
    if(wasbuff) {
      if (objectp(caster)) {
        caster->set_property("magic resistance",(-1*lower));
        caster->set_property("raised resistance",-1);
        tell_room(environment(caster),"%^MAGENTA%^Energy flickers briefly around "+caster->QCN+" before waning.%^RESET%^",caster);
        tell_object(caster,"%^MAGENTA%^A breath of cool air reaches your skin as the protective invocation flickers and wanes!%^RESET%^");
      }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
