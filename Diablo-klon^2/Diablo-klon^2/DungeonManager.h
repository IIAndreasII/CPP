#ifndef DM_H
#define DM_H

class Dungeon;
class Player;

class DungeonManager
{
public:
	DungeonManager();
	~DungeonManager();

	void Reset();

	Dungeon& GetDungeon();

private:
	Dungeon* myDungeon;
};

#endif