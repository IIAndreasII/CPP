#ifndef DM_H
#define DM_H

class Dungeon;
class Player;

class DungeonManager
{

public:
	DungeonManager();
	~DungeonManager();

	void ViewMap();

private:
	Dungeon* myDungeon;

	Player& myPlayer;

};

#endif