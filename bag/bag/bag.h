/*------------------------------------bag.h
Purpose: defines a template bag class which contains an array and functions for manipulating it.

--- Member Data ---
Name            Type              Description
-------------------------------------------------------------------------------------------
MAX_ITEMS	   static const int   Sets max array size
itemArray[]    class TYPE         an array of size MAX_ITEMS
itemCount      int                number of used indices in the array
roomToAdd      bool               used to ensure array does not go out of bounds, return for addItem()      

--- Functions ---
Name                Return    Description; Parameter description
--------------------------------------------------------------------------------------------
Bag()			    none      Default constructor
	no params

getCount()			int       returns itemCount to client
	no params

addItem()           bool      if there is room, adds argument to array. Returns success/fail
    TYPE& newEntry            address of item to be added to array

findItem() const    int       checks through array to find index matching parameter value
	TYPE itemToFind           value to be searched for

deleteItem()        bool      deletes an item from array, moves last entry to empty place and reduces array size
    int itemNum               index of item to be removed

empty()				bool      sets itemCount to 0
	no params

toVector() const	vector<TYPE>   reads array into a vector and returns the vector
	no params
*/

#ifndef _BAG_INTERFACE_
#define _BAG_INTERFACE_

#include "utility.h"

template<class TYPE> 
class Bag
{
private:
	static const int MAX_ITEMS = 15;
	TYPE itemArray[MAX_ITEMS];
	int itemCount;
public:
	Bag();
	bool addItem(const TYPE& newEntry);
	int getCount() const;
	int findItem(TYPE itemToFind, int i) const;
	bool deleteItem(int itemNum);
	bool empty();
	vector<TYPE> toVector() const;
};

//Default constructor
template<class TYPE>
Bag<TYPE>::Bag()
{
	itemCount = 0;
}

//if there is room, adds argument to array. Returns success/fail
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

//deletes an item from array, moves last entry to empty place and reduces array size
template<class TYPE>
bool Bag<TYPE>::deleteItem(int itemNum)
{
	if(itemNum > itemCount || itemNum < 0)
	{
		return false;
	}
	else
	{
		itemArray[itemNum] = itemArray[itemCount-1];
		itemCount--;
	}
	return true;
}

template<class TYPE>
bool Bag<TYPE>::empty()
{
	cout<<"Emptying ...";
	itemCount = 0;
	return true;
}

//checks through array to find index matching parameter value
//Also, it's recursive
template<class TYPE>
int Bag<TYPE>::findItem(TYPE itemToFind, int i) const
{
	if(itemToFind == itemArray[i])
	{
		return i;
	}
	else if(i >= itemCount)
	{
		return -1;
	}
	else
	{
		return findItem(itemToFind, i+1);
	}
}

//returns itemCount to client
template<class TYPE>
int Bag<TYPE>::getCount() const
{
	return itemCount;
}

//reads array into a vector and returns the vector
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

#endif