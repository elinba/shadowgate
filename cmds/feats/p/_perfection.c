#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("RisenMartyr");
    feat_name("perfection");
    feat_prereq("Risen Martyr L7");
    feat_desc("The Risen Martyr has become as close to celestial perfection as a mortal can be. " +
              "She embodies the very essence of an Archon, Eladrin, or Guardinal celestial. " +
              "The Risen Martyr with this feat gains complete immunity to Electricity, Cold and Acid.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("risen_martyr") < 7)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob)
{
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob)
{
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}