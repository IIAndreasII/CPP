#ifndef ENUMS_H
#define ENUMS_H

enum EAttackType
{
	SLASH,
	SWEEP,
	WHIRLWIND,
	ICELANCE,
	COC, // Cone of Cold
	BLIZZARD
};

enum EItemType
{
	SWORD,
	STAFF,
	ARMOUR,
	SPELLARMOUR,
	RING
};

enum ERingType
{
	NOT_A_RING,
	VITALITY,
	DEFENCE,
	STRENGTH,
	INTELLIGENCE
};

enum EDamageType
{
	PHYSICAL,
	MAGICAL
};

#endif