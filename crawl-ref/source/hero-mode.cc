#include "AppHdr.h"

#include "hero-mode.h"

#include "religion.h"

int hero_mode_modify_exp_1(int exp)
{
    return exp * HERO_MODE_MULTIPLIER;
}

int hero_mode_modify_exp_inverse_1(int exp)
{
    return div_rand_round(exp, HERO_MODE_MULTIPLIER);
}

int hero_mode_modify_piety_1(int piety)
{
    // usk is tactical, oka gives bonus piety for scary monsters (all of them)
    if (you_worship(GOD_OKAWARU) || you_worship(GOD_USKAYAW))
        return piety;

    if (you_worship(GOD_ASHENZARI)
        || you_worship(GOD_NEMELEX_XOBEH)
        || you_worship(GOD_HEPLIAKLQANA)
        || you_worship(GOD_RU))
    {
        return piety * HERO_MODE_MULTIPLIER * 3; // exploration piety
    }

    return piety * HERO_MODE_MULTIPLIER;
}
