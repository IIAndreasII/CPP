#include "stdafx.h"
#include "Shop.h"
#include "Util.h"
#include "Player.h"
#include <thread>

Shop::Shop() : myItems()
{
}

Shop::Shop(Player* aPlayerPtr) : myItems(), myPlayerPtr(aPlayerPtr)
{
}

Shop::~Shop()
{
	SafeDelete(myPlayerPtr);
}

void Shop::Restock()
{
	myItems.clear();
	for (size_t i = 0; i < 3; i++)
	{
		Item tempItem(myPlayerPtr->GetLevel());
	}
	myEstusAmount = 2;
}

void Shop::Enter()
{
	bool tempLoop = true;
	while (tempLoop)
	{
		CLSSlow();
		myPlayerPtr->PrintUI();
		Print("Welcome to the shop\n\n___| Items for sale |___");
		for (size_t i = 0; i < 3; i++)
		{
			Print("[" + std::to_string(i + 1) + "] " + myItems.at(i).GetName() + " [Level: " + std::to_string(myItems.at(i).GetLevel()) + "  Stat: " + std::to_string(myItems.at(i).GetStat()) + "] - " + std::to_string(40 * myItems.at(i).GetLevel()) + " gold");
		}
		Print("[4] Estus flask (" + std::to_string(myEstusAmount) + "available) - 30 gold\n[5] Learn skills\n[6] Back");
		int tempInput = 0;
		bool tempInnerLoop = true;
		switch (GetInput(tempInput))
		{
		case 4:
			if (30 <= myPlayerPtr->GetGold() && myEstusAmount > 0)
			{
				myPlayerPtr->AddGold(-30);
				myEstusAmount -= 1;
			}
			break;
		case 5:
			while (tempInnerLoop)
			{
				CLSSlow();
				myPlayerPtr->PrintUI();
				Print("___| Skills to learn |___");

				for (size_t i = 0; i < mySkills.size(); i++)
				{
					Print("[" + std::to_string(i + 1) + "] " + myPlayerPtr->AtkTypeToString(mySkills.at(i)) + " - 150 gold");
				}
				Print("[4] Back");

				int tempInnerInput = 0;
				switch (GetInput(tempInnerInput))
				{
				case 4:
					tempInnerLoop = false;
					break;
				default:
					if (tempInnerInput > 0 && tempInnerInput <= mySkills.size() && myPlayerPtr->GetGold() >= 150)
					{
						myPlayerPtr->AddGold(-150);
						myPlayerPtr->AddAttackType(mySkills.at(tempInnerInput - 1));
					}
					break;
				}
			}
			break;
		case 6:
			tempLoop = false;
			break;
		default:
			if (tempInput > 0 && tempInput < 4)
			{
				tempInput--; // Compensate
				if (40 * myItems.at(tempInput).GetLevel() >= myPlayerPtr->GetGold())
				{
					myPlayerPtr->AddItem(myItems.at(tempInput));
					myPlayerPtr->AddGold(-40 * myItems.at(tempInput).GetLevel());
				}
				else
				{
					Print("Insufficient funds!");
					std::this_thread::sleep_for(std::chrono::seconds(1));
				}
				break;
			}
			
		}
	}
}

void Shop::SetPlayerPtr(Player* aPlayerPtr)
{
	myPlayerPtr = aPlayerPtr;
}

void Shop::AddAttackType(EAttackType anAtkType)
{
	if (!(std::find(mySkills.begin(), mySkills.end(), anAtkType) != mySkills.end()))
	{
		mySkills.push_back(anAtkType);
	}
}
