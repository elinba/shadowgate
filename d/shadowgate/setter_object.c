#include <daemons.h>

inherit OBJECT;

string *ROLL_CHAIN = ({"class", "race", "subrace", "template", "stats"});

string *SPECIAL_CHAIN = ({"stats"});

int head = 0;

mapping char_sheet = ([]);

void create()
{
    ::create();
    set_short("%^MAGENTA%^A strange and powerful object%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This strange object radiates power " +
             "the likes of which you have never before seen. It seems to contain " +
             "the very essence of life, allowing one who holds it to " +
             "make choices which will alter the very fabric of their being. " +
             "You may <%^BOLD%^%^CYAN%^check%^BOLD%^%^WHITE%^> to glimpse " +
             "what choices it contains. You may <%^BOLD%^%^CYAN%^reset choice" +
             "%^BOLD%^%^WHITE%^> to alter one if you are unhappy with it. You " +
             "may <%^BOLD%^%^CYAN%^review%^BOLD%^%^WHITE%^> to see a list " +
             "of current options that this object affords you. It has " +
             "attached itself to you and will be with you for as long as you " +
             "are a newbie character in the world of ShadowGate.%^RESET%^");
    /* set_property("no drop", 1); */
    /* set_property("death keep", 1); */
    set_id(({ "setter object", "object", "charactercreationsetterobject" }));
    set_weight(0);
    /* set_property("no animate", 1); */
    /* set_property("soulbound", 1); */
}

void init()
{
    ::init();
    /* if (userp(ETO)) */
    /*     if (!newbiep(ETO)) { */
    /*         TO->remove(); */
    /*     } */
// actions to add: reset done reroll add review pick check finalize brief recommended random
    add_action("_pick", "pick");
    add_action("_review", "review");
}

_pick(string str)
{
    if (select_common(str)) {
        advance_head();
    } else {
        display_common();
    }
    return 1;
}

_review()
{
    display_common();
    return 1;
}

advance_head()
{
    head++;
    if (head >= sizeof(ROLL_CHAIN)) {
        review();
    } else {
        display_common();
    }
}

select_common(string str)
{
    string * choices;


    if (member_array(ROLL_CHAIN[head], SPECIAL_CHAIN) != -1) {
        call_other(TO, "select_" + ROLL_CHAIN[head]);
        return;
    }

    choices = call_other(TO, "generate_" + ROLL_CHAIN[head]);

    if (sizeof(choices)) {
        if (!member_array(str, choices)) {
            write("INVALID SELECTION " + str);
            return 0;
        }
    }

    char_sheet[ROLL_CHAIN[head]] = str;
    return 1;
}

display_common()
{
    string i;
    string * choices;

    if (member_array(ROLL_CHAIN[head], SPECIAL_CHAIN) != -1) {
        call_other(TO, "display_" + ROLL_CHAIN[head]);
        return;
    }

    choices = call_other(TO, "generate_" + ROLL_CHAIN[head]);

    if (sizeof(choices) > 1) {
        foreach(i in choices)
        {
            write("%^BOLD%^%^MAGENTA%^" + capitalize(i));
        }
    } else if (sizeof(choices) == 1) {
        select_common(choices[0]);
    } else {
        advance_head();
    }
}

// MODULES

string *generate_class()
{
    string * choices;

    choices = get_dir("/std/class/*.c");
    choices = map(choices, (:replace_string($1, ".c", ""):));
    choices = filter_array(choices, (:!("/std/class/" + $1)->is_prestige_class():));
    choices = filter_array(choices, (:!("/std/class/" + $1)->is_locked_class():));

    return choices;
}

string *generate_race()
{
    string * choices;

    choices = get_dir("/std/races/*.c");
    choices = map(choices, (:replace_string($1, ".c", ""):));
    choices = filter_array(choices, (:member_array($1, ("/std/class/" + $2)->restricted_races()) == -1:), char_sheet["class"]);

    return choices;
}

string *generate_subrace()
{
    string * choices = ({});

    choices = ("/std/races/" + char_sheet["race"])->query_subraces(ETO);
    if (sizeof(choices)) {
        choices = filter_array(choices, (:
                                member_array($2, ("/std/races/" + char_sheet["race"])->restricted_classes($1)) == -1
                                :), char_sheet["class"]);
    }

    return choices;
}

string *generate_template()
{
    string * choices = ({});

    choices = map(filter_array(map(get_dir("/std/acquired_template/*.c"),(:"/std/acquired_template/" + $1:)), (:member_array($2, arrayp($1->races_allowed()) ? $1->races_allowed() : ({$2})) != -1:), char_sheet["race"]), (: replace_string(replace_string($1, "/std/acquired_template/", ""), ".c", "") :));

    return choices;
}
