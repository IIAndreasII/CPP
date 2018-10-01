#ifndef ITEM_H
#define ITEM_H

enum EItemType
{

};

class Item
{
public:
	Item();
	~Item();


	EItemType& GetItemType();

private:

	EItemType myItemType;
};

#endif