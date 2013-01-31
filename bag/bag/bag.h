#include "utility.h"
#include <vector>

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
	void list() const;
	bool deleteItem();
	bool empty();
	vector<TYPE> toVector();
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
bool Bag<TYPE>::deleteItem()
{
	return true;
}

template<class TYPE>
bool Bag<TYPE>::empty()
{
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
	return count;
}

template<class TYPE>
void Bag<TYPE>::list() const
{

}


template<class TYPE>
vector<TYPE> Bag<TYPE>::toVector()
{
	vector<TYPE> bagItems;

	for(int i=0; i<itemCount; i++)
	{
		bagItems.push_back(itemArray[i]);
	}
	return bagItems;
}