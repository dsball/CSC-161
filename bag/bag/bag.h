#include "utility.h"

template<class TYPE> 
class Bag
{
private:
	static const int MAX_ITEMS = 10;
	TYPE itemArray[MAX_ITEMS];
	int itemCount;
public:
	Bag();
	bool addItem(const TYPE& newEntry);
	int getCount() const;
	bool findItem() const;
	bool deleteItem(int itemNum);
	bool empty();
	vector<TYPE> toVector() const;
};

template<class TYPE>
Bag<TYPE>::Bag()
{
	itemCount = 0;
}

template<class TYPE>
bool Bag<TYPE>::addItem(const TYPE& newEntry)
{
	bool roomToAdd = (itemCount < MAX_ITEMS);
	if(roomToAdd)
	{
		itemArray[itemCount] = newEntry;
		itemCount++;
	}
	return roomToAdd;
}

template<class TYPE>
bool Bag<TYPE>::deleteItem(int itemNum)
{
	itemArray[itemNum] = itemArray[itemCount-1];
	itemCount--;
	return true;
}

template<class TYPE>
bool Bag<TYPE>::empty()
{
	cout<<"Emptying ...";
	itemCount = 0;
	return true;
}

template<class TYPE>
bool Bag<TYPE>::findItem() const
{
	return true;
}

template<class TYPE>
int Bag<TYPE>::getCount() const
{
	return itemCount;
}

template<class TYPE>
vector<TYPE> Bag<TYPE>::toVector() const
{
	vector<TYPE> bagItems;

	for(int i=0; i<itemCount; i++)
	{
		bagItems.push_back(itemArray[i]);
	}
	return bagItems;
}